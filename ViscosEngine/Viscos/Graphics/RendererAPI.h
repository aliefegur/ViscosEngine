#pragma once

#include "Viscos/Core/API.h"

namespace Viscos {

	class VISCOS_API RendererAPI
	{
	public:
		virtual ~RendererAPI() = default;
		
		virtual void Clear(float r, float g, float b, float a) = 0;

		static RendererAPI* Create();
	};

}
