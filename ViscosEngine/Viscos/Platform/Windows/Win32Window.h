#pragma once

#include "Viscos/Core/Window.h"

namespace Viscos {

	class Win32Window : public Window
	{
	public:
		Win32Window(const WindowProperties& props);
		~Win32Window();

		void OnUpdate() override;

		uint32_t GetWidth() const override;
		uint32_t GetHeight() const override;

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		void* GetNativeWindow() const override;
	};

}
