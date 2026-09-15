#include "Win32Window.h"

#include "Viscos/Core/Log.h"
#include "Viscos/Events/KeyEvents.h"
#include "Viscos/Events/MouseEvents.h"
#include "Viscos/Events/WindowEvents.h"

namespace Viscos {

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

		default:
		{
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		}
	}

}
