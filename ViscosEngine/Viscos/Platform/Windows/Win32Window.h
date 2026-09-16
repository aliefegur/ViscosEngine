#pragma once

#include "Viscos/Core/Window.h"
#include "Win32Input.h"

#include <Windows.h>

namespace Viscos {

	class Win32Window final : public Window
	{
		friend class Win32WindowClass;
	public:
		Win32Window(const WindowProperties& props);
		~Win32Window() override;

		void OnUpdate() override;

		uint32_t GetWidth() const override;
		uint32_t GetHeight() const override;

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		void* GetNativeWindow() const override;

	private:
		static LRESULT CALLBACK HandleMsgSetup(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) noexcept;
		static LRESULT CALLBACK HandleMsgThunk(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) noexcept;
		LRESULT HandleMsg(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) noexcept;

	private:
		struct WindowData
		{
			std::string Title;
			uint32_t Width = 0;
			uint32_t Height = 0;
			bool VSync = true;
		};

		WindowData m_Data;

		std::unique_ptr<Win32Input> m_Input;

		HWND m_Hwnd;

	private:
		template <typename T, typename... Args>
		void DispatchEvent(Args&&... args)
		{
			if (m_EventCallback)
			{
				T event(std::forward<Args>(args)...);
				m_EventCallback(event);
			}
		}
	};

}
