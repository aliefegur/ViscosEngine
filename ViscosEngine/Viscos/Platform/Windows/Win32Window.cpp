#include "Win32Window.h"

#include "Viscos/Core/Log.h"
#include "Viscos/Core/Input/Input.h"
#include "Viscos/Events/KeyEvents.h"
#include "Viscos/Events/MouseEvents.h"
#include "Viscos/Events/WindowEvents.h"

namespace Viscos {

	static KeyCode TranslateKeyCode(uint32_t virtualKey, LPARAM lParam);

	class Win32WindowClass
	{
	public:
		static LPCSTR GetName() noexcept
		{
			return s_ClassName;
		}

		static HINSTANCE GetInstance() noexcept
		{
			return s_WindowClass.m_Instance;
		}

	private:
		Win32WindowClass() noexcept : m_Instance(GetModuleHandle(nullptr))
		{
			WNDCLASSEX wc{};
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.style = CS_OWNDC;
			wc.lpfnWndProc = Win32Window::HandleMsgSetup;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hInstance = GetInstance();
			wc.hIcon = LoadIcon(GetInstance(), MAKEINTRESOURCE(101));
			wc.hIconSm = nullptr;
			wc.hCursor = nullptr;
			wc.hbrBackground = nullptr;
			wc.lpszMenuName = nullptr;
			wc.lpszClassName = GetName();

			RegisterClassEx(&wc);
		}

		~Win32WindowClass()
		{
			UnregisterClass(GetName(), GetInstance());
		}

	private:
		static constexpr LPCSTR s_ClassName = "ViscosWin32WindowClass";
		static Win32WindowClass s_WindowClass;
		HINSTANCE m_Instance;
	};

	Win32WindowClass Win32WindowClass::s_WindowClass = Win32WindowClass();
	

	Win32Window::Win32Window(const WindowProperties& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.VSync = true;

		constexpr DWORD windowStyle = WS_CAPTION | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_SYSMENU;

		RECT windowRect;
		windowRect.left = 100;
		windowRect.right = m_Data.Width + windowRect.left;
		windowRect.top = 100;
		windowRect.bottom = m_Data.Height + windowRect.top;

		if (AdjustWindowRect(&windowRect, windowStyle, FALSE) == 0)
		{
			VSCS_CORE_ERROR("Failed to adjust window rectangle!");
			// TODO: Handle HRESULT exceptions
		}

		const int windowWidth = windowRect.right - windowRect.left;
		const int windowHeight = windowRect.bottom - windowRect.top;

		m_Hwnd = CreateWindow(
			Win32WindowClass::GetName(),
			m_Data.Title.c_str(),
			windowStyle,
			CW_USEDEFAULT, CW_USEDEFAULT,
			windowWidth, windowHeight,
			nullptr, nullptr,
			Win32WindowClass::GetInstance(),
			this
		);

		if (m_Hwnd == nullptr)
		{
			VSCS_CORE_ERROR("Failed to create Win32Window!");
			// TODO: Handla HRESULT exceptions
		}

		ShowWindow(m_Hwnd, SW_SHOW);
		UpdateWindow(m_Hwnd);
	}

	Win32Window::~Win32Window()
	{
		DestroyWindow(m_Hwnd);
	}

	void Win32Window::OnUpdate()
	{
		MSG msg;

		while (PeekMessage(&msg, m_Hwnd, NULL, NULL, PM_REMOVE) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	uint32_t Win32Window::GetWidth() const
	{
		return m_Data.Width;
	}

	uint32_t Win32Window::GetHeight() const
	{
		return m_Data.Height;
	}

	void Win32Window::SetVSync(bool enabled)
	{
		// TODO: Implement VSync
	}

	bool Win32Window::IsVSync() const
	{
		return m_Data.VSync;
	}

	void* Win32Window::GetNativeWindow() const
	{
		return static_cast<void*>(m_Hwnd);
	}

	LRESULT Win32Window::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		if (msg == WM_NCCREATE)
		{
			const auto* create = reinterpret_cast<CREATESTRUCT*>(lParam);
			auto* window = static_cast<Win32Window*>(create->lpCreateParams);

			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Win32Window::HandleMsgThunk));

			return window->HandleMsg(hWnd, msg, wParam, lParam);
		}

		return DefWindowProcA(
			hWnd,
			msg,
			wParam,
			lParam
		);
	}

	LRESULT Win32Window::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		auto* window = reinterpret_cast<Win32Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		return window->HandleMsg(hWnd, msg, wParam, lParam);
	}

	LRESULT Win32Window::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
	{
		switch (msg)
		{
		case WM_CLOSE:
		{
			DispatchEvent<WindowCloseEvent>();
			return 0;
		}

		case WM_SIZE:
		{
			const uint32_t w = LOWORD(lParam);
			const uint32_t h = HIWORD(lParam);

			m_Data.Width = w;
			m_Data.Height = h;

			DispatchEvent<WindowResizeEvent>(w, h);

			return 0;
		}

		case WM_SETFOCUS:
		{
			DispatchEvent<WindowFocusEvent>();
			return 0;
		}

		case WM_KILLFOCUS:
		{
			DispatchEvent<WindowLostFocusEvent>();
			return 0;
		}

		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		{
			const KeyCode key = TranslateKeyCode(static_cast<uint32_t>(wParam), lParam);
			DispatchEvent<KeyPressedEvent>(key, (static_cast<uint32_t>(lParam) & 0x40000000) != 0);
			return 0;
		}

		case WM_KEYUP:
		case WM_SYSKEYUP:
		{
			const KeyCode key = TranslateKeyCode(static_cast<uint32_t>(wParam), lParam);
			DispatchEvent<KeyReleasedEvent>(key);
			return 0;
		}

		default: return DefWindowProc(hWnd, msg, wParam, lParam);

		}
	}

	KeyCode TranslateKeyCode(uint32_t virtualKey, LPARAM lParam)
	{
		VSCS_CORE_TRACE(virtualKey);

		switch (virtualKey)
		{
		case VK_SHIFT:
		{
			const uint32_t scanCode = (static_cast<uint32_t>(lParam) >> 16) & 0xFF;
			return scanCode == 0x36 ? KeyCode::RightShift : KeyCode::LeftShift;
		}

		case VK_CONTROL:
		{
			const bool extended = (static_cast<uint32_t>(lParam) & 0x01000000) != 0;
			return extended ? KeyCode::RightControl : KeyCode::LeftControl;
		}

		case VK_MENU:
		{
			const bool extended = (static_cast<uint32_t>(lParam) & 0x01000000) != 0;
			return extended ? KeyCode::RightAlt : KeyCode::LeftAlt;
		}

		case VK_SPACE:	return KeyCode::Space;
		case VK_ESCAPE:	return KeyCode::Escape;
		case VK_RETURN:	return KeyCode::Enter;
		case VK_TAB:	return KeyCode::Tab;
		case VK_BACK:	return KeyCode::Backspace;
		case VK_INSERT:	return KeyCode::Insert;
		case VK_DELETE:	return KeyCode::Delete;

		case VK_RIGHT:		return KeyCode::Right;
		case VK_LEFT:		return KeyCode::Left;
		case VK_DOWN:		return KeyCode::Down;
		case VK_UP:			return KeyCode::Up;

		case VK_PRIOR:		return KeyCode::PageUp;
		case VK_NEXT:		return KeyCode::PageDown;
		case VK_HOME:		return KeyCode::Home;
		case VK_END:		return KeyCode::End;

		case VK_CAPITAL:	return KeyCode::CapsLock;
		case VK_SCROLL:		return KeyCode::ScrollLock;
		case VK_NUMLOCK:	return KeyCode::NumLock;

		case VK_SNAPSHOT:	return KeyCode::PrintScreen;
		case VK_PAUSE:		return KeyCode::Pause;

		case VK_F1:		return KeyCode::F1;
		case VK_F2:		return KeyCode::F2;
		case VK_F3:		return KeyCode::F3;
		case VK_F4:		return KeyCode::F4;
		case VK_F5:		return KeyCode::F5;
		case VK_F6:		return KeyCode::F6;
		case VK_F7:		return KeyCode::F7;
		case VK_F8:		return KeyCode::F8;
		case VK_F9:		return KeyCode::F9;
		case VK_F10:	return KeyCode::F10;
		case VK_F11:	return KeyCode::F11;
		case VK_F12:	return KeyCode::F12;

		case VK_NUMPAD0:	return KeyCode::Num0;
		case VK_NUMPAD1:	return KeyCode::Num1;
		case VK_NUMPAD2:	return KeyCode::Num2;
		case VK_NUMPAD3:	return KeyCode::Num3;
		case VK_NUMPAD4:	return KeyCode::Num4;
		case VK_NUMPAD5:	return KeyCode::Num5;
		case VK_NUMPAD6:	return KeyCode::Num6;
		case VK_NUMPAD7:	return KeyCode::Num7;
		case VK_NUMPAD8:	return KeyCode::Num8;
		case VK_NUMPAD9:	return KeyCode::Num9;
		case VK_DECIMAL:	return KeyCode::NumDecimal;
		case VK_DIVIDE:		return KeyCode::NumDivide;
		case VK_MULTIPLY:	return KeyCode::NumMultiply;
		case VK_SUBTRACT:	return KeyCode::NumSubtract;
		case VK_ADD:		return KeyCode::NumAdd;

		case VK_APPS:	return KeyCode::Menu;

		// OEM / punctuation keys
		case VK_OEM_1:		return KeyCode::Semicolon;
		case VK_OEM_PLUS:	return KeyCode::Equal;
		case VK_OEM_COMMA:	return KeyCode::Comma;
		case VK_OEM_MINUS:	return KeyCode::Minus;
		case VK_OEM_PERIOD:	return KeyCode::Period;
		case VK_OEM_2:		return KeyCode::Slash;
		case VK_OEM_3:		return KeyCode::GraveAccent;
		case VK_OEM_4:		return KeyCode::LeftBracket;
		case VK_OEM_5:		return KeyCode::Backslash;
		case VK_OEM_6:		return KeyCode::RightBracket;
		case VK_OEM_7:		return KeyCode::Apostrophe;
		case VK_OEM_8:      return KeyCode::OEM8;
		case VK_OEM_102:    return KeyCode::OEM102;

		default: break;
		}

		// Alphabetic keys
		if (virtualKey >= 'A' && virtualKey <= 'Z')
		{
			return static_cast<KeyCode>(
				static_cast<uint16_t>(KeyCode::A) +
				(virtualKey - 'A')
				);
		}

		// Numeric keys
		if (virtualKey >= '0' && virtualKey <= '9')
		{
			return static_cast<KeyCode>(
				static_cast<uint16_t>(KeyCode::D0) + (virtualKey - '0')
				);
		}

		return KeyCode::Unknown;
	}

}
