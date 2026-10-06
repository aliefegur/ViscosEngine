#pragma once

#include "Viscos/Core/API.h"

namespace Viscos {

	class VISCOS_API Renderer
	{
	public:
		static void Initialize();
		static void Shutdown();

		static void Clear(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f);
	};

}
