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

		virtual void EndFrame() = 0;

		GraphicsAPI GetAPI() const noexcept;

		// Factory function
		static std::unique_ptr<Graphics> Create(GraphicsAPI api, NativeHandle nativeWindow);

	protected:
		GraphicsAPI m_TargetAPI;
		NativeHandle m_NativeWindow;
	};

}
