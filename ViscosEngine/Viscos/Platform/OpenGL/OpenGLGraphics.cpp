#include "OpenGLGraphics.h"

#include "Viscos/Core/Log.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

// TODO: Implement an internal exception system!

namespace Viscos {

	OpenGLGraphics::OpenGLGraphics(const NativeHandle nativeWindow)
		: Graphics(nativeWindow)
	{
		// Platform-specific device creation
#ifdef VISCOS_PLATFORM_WINDOWS
		PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
			PFD_TYPE_RGBA,			// The kind of framebuffer. RGBA or palette.
			32,						// Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,						// Number of bits for the depthbuffer
			8,						// Number of bits for the stencilbuffer
			0,						// Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		m_Device = GetDC(static_cast<HWND>(nativeWindow));

		int letWindowChoosePixelFormat = ChoosePixelFormat(m_Device, &pfd);
		SetPixelFormat(m_Device, letWindowChoosePixelFormat, &pfd);
#endif

		// Context
		m_Context = wglCreateContext(m_Device);

		// Make context current
		wglMakeCurrent(m_Device, m_Context);

		// Load modern OpenGL via glad library
		if (!gladLoadGL())
		{
			VSCS_CORE_ERROR("Failed to load modern OpenGL functions!");
		}

		// We are going to WGL for V-Sync
		if (!gladLoadWGL(m_Device))
		{
			VSCS_CORE_ERROR("Failed to load WGL functions!");
		}

		// Enable V-Sync
		// TODO: Abstract V-Sync system
		wglSwapIntervalEXT(1);
		
		// Initial Viewport
		glViewport(0, 0, 1280, 720);

		// Enable alpha blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		VSCS_CORE_TRACE("OpenGL Version: {}.{}", GLVersion.major, GLVersion.minor);

		s_TargetAPI = GraphicsAPI::OpenGL;
	}

	OpenGLGraphics::~OpenGLGraphics()
	{
#ifdef VISCOS_PLATFORM_WINDOWS
		wglDeleteContext(m_Context);
		ReleaseDC(static_cast<HWND>(m_NativeWindow), m_Device);
#endif
	}

	void OpenGLGraphics::Present()
	{
#ifdef VISCOS_PLATFORM_WINDOWS
		if (SwapBuffers(m_Device) == FALSE)
		{
			VSCS_CORE_ERROR("Failed to swap framebuffers!");
		}
#endif
	}

}
