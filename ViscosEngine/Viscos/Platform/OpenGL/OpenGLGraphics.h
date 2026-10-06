#pragma once

#include "Viscos/Graphics/Graphics.h"

namespace Viscos {

	class OpenGLGraphics : public Graphics
	{
		OpenGLGraphics(const Window::NativeHandle nativeWindow) : Graphics(nativeWindow) {};
		~OpenGLGraphics() = default;
	};

}
