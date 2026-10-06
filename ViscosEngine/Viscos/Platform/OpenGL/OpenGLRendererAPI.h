#pragma once

#include "Viscos/Graphics/RendererAPI.h"

namespace Viscos {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		~OpenGLRendererAPI() override = default;

		void Clear(float r, float g, float b, float a) override;
	};

}
