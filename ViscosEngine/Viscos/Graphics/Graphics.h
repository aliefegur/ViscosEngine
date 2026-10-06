#pragma once

#include "Viscos/Core/Window.h"

#include <memory>

namespace Viscos {

	class Graphics
	{
	public:
		Graphics(const Window::NativeHandle nativeWindow);
		Graphics(const Graphics&) = delete;
		Graphics& operator=(const Graphics&) = delete;
		virtual ~Graphics() = default;

		virtual void EndFrame() = 0;

		GraphicsAPI GetAPI() const noexcept;

		// Factory function
		static std::unique_ptr<Graphics> Create(GraphicsAPI api, Window::NativeHandle nativeWindow);

	protected:
		GraphicsAPI m_TargetAPI;
		Window::NativeHandle m_NativeWindow;
	};

}
