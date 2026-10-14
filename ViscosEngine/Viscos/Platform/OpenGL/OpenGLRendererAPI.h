#pragma once

#include "Viscos/Graphics/RendererAPI.h"

namespace Viscos {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		~OpenGLRendererAPI() override = default;

		void Clear(float r, float g, float b, float a) override;
		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
	};

}
