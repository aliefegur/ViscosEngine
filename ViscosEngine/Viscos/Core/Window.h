#pragma once

#include "API.h"
#include "Viscos/Events/Event.h"

#include <string>
#include <cstdint>
#include <functional>

namespace Viscos {

	struct WindowProperties
	{
		std::string Title = "Viscos Engine";
		uint32_t Width = 1280;
		uint32_t Height = 720;
	};

	class VISCOS_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
	
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		void SetEventCallback(const EventCallbackFn& callback);

		static std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties{});

	protected:
		EventCallbackFn m_EventCallback;
	};

}
