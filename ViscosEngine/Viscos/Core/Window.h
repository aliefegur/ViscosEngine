#pragma once

#include "API.h"
#include "Viscos/Events/Event.h"
#include "Viscos/Graphics/GraphicsAPI.h"

#include <string>
#include <cstdint>
#include <functional>
#include <memory>

namespace Viscos {

	class Graphics;

	struct WindowProperties
	{
		std::string Title = "Viscos Engine";
		uint32_t Width = 1280;
		uint32_t Height = 720;

		GraphicsAPI GraphicsAPI = GraphicsAPI::OpenGL;
	};

	class VISCOS_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		using NativeHandle = void*;
	
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual NativeHandle GetNativeWindow() const = 0;

		void SetEventCallback(const EventCallbackFn& callback);

		void InitializeGraphics(GraphicsAPI api);

		static std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties{});

	protected:
		EventCallbackFn m_EventCallback;
		std::unique_ptr<Graphics> m_Graphics;
	};

}
