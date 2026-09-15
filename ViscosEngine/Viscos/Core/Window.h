#pragma once

#include "API.h"

#include <string>
#include <cstdint>

namespace Viscos {

	struct WindowProperties
	{
		std::string Title = "Viscos Engine";
		uint32_t Width = 1280;
		uint16_t Height = 720;
	};

	class VISCOS_API Window
	{
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties{});
	};

}
