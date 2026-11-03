#pragma once

#include "API.h"
#include "NativeHandle.h"
#include "Viscos/Events/Event.h"
#include "Viscos/Graphics/Graphics.h"

#include <string>
#include <cstdint>
#include <functional>
#include <memory>

namespace Viscos {

	struct WindowProperties
	{
		std::string Title = "Viscos Engine";
		uint32_t Width = 1280;
		uint32_t Height = 720;

		GraphicsAPI GraphicsAPI = GraphicsAPI::OpenGL;
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
	
	public:
		virtual ~Window() = default;

		virtual VISCOS_API void OnUpdate();

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual NativeHandle GetNativeWindow() const = 0;

		VISCOS_API void SetEventCallback(const EventCallbackFn& callback);

		VISCOS_API void InitializeGraphics(GraphicsAPI api);

		static VISCOS_API std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties{});

	protected:
		EventCallbackFn m_EventCallback;
		std::unique_ptr<Graphics> m_Graphics;
	};

}
