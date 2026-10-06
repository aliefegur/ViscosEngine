#pragma once

#include "GraphicsAPI.h"
#include "Viscos/Core/NativeHandle.h"

#include <memory>

namespace Viscos {

	class Graphics
	{
	public:
		Graphics(const NativeHandle nativeWindow);
		Graphics(const Graphics&) = delete;
		Graphics& operator=(const Graphics&) = delete;
		virtual ~Graphics() = default;

		virtual void Present() = 0;

		static GraphicsAPI GetAPI() noexcept;

		// Factory function
		static std::unique_ptr<Graphics> Create(GraphicsAPI api, NativeHandle nativeWindow);

	protected:
		static GraphicsAPI s_TargetAPI;
		NativeHandle m_NativeWindow;
	};

}
