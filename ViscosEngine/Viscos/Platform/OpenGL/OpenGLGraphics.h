#pragma once

#include "Viscos/Graphics/Graphics.h"

#ifdef VISCOS_PLATFORM_WINDOWS
#include <Windows.h>
#endif

namespace Viscos {

	class OpenGLGraphics : public Graphics
	{
	public:
		OpenGLGraphics(const NativeHandle nativeWindow);
		~OpenGLGraphics() override;

		void Present() override;

	private:
#ifdef VISCOS_PLATFORM_WINDOWS
		HGLRC	m_Context = nullptr;
		HDC		m_Device = nullptr;
#endif
	};

}
