#pragma once

#include "Viscos/Core/API.h"

namespace Viscos {

	class VISCOS_API RendererAPI
	{
	public:
		virtual ~RendererAPI() = default;
		
		virtual void Clear(float r, float g, float b, float a) = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		static RendererAPI* Create();
	};

}
