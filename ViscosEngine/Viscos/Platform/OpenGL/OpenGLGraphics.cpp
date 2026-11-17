#include "OpenGLGraphics.h"

#include "Viscos/Core/Log.h"
#include "Viscos/Core/Exception.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

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
		if (!m_Device)
			throw ViscosException("Failed to get OpenGL device!");

		int pixelFormat = ChoosePixelFormat(m_Device, &pfd);
		if (pixelFormat == 0)
		{
			const DWORD errorCode = GetLastError();
			ReleaseDC(static_cast<HWND>(m_NativeWindow), m_Device);
			throw ViscosException(std::format("Failed to choose pixel format! Error code: 0x{:08x}", errorCode));
		}

		if (!SetPixelFormat(m_Device, pixelFormat, &pfd))
		{
			const DWORD errorCode = GetLastError();
			ReleaseDC(static_cast<HWND>(m_NativeWindow), m_Device);
			throw ViscosException(std::format("Failed to set pixel format! Error code: 0x{:08x}", errorCode));
		}
#endif

		// Context
		m_Context = wglCreateContext(m_Device);
		if (!m_Context)
		{
#ifdef VISCOS_PLATFORM_WINDOWS
			ReleaseDC(static_cast<HWND>(m_NativeWindow), m_Device);
#endif
			throw ViscosException("Failed to create OpenGL context!");
		}

		// Make context current
		if (!wglMakeCurrent(m_Device, m_Context))
		{
			wglDeleteContext(m_Context);
#ifdef VISCOS_PLATFORM_WINDOWS
			ReleaseDC(static_cast<HWND>(m_NativeWindow), m_Device);
#endif
			throw ViscosException("Failed to make OpenGL context current!");
		}

		// Load modern OpenGL via glad library
		if (!gladLoadGL()) {
			wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(m_Context);
#ifdef VISCOS_PLATFORM_WINDOWS
			ReleaseDC(static_cast<HWND>(m_NativeWindow), m_Device);
#endif
			throw ViscosException("Failed to load modern OpenGL functions!");
		}
		
		// Loading WGL functions for OpenGL context management
		if (!gladLoadWGL(m_Device)) {
			wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(m_Context);
#ifdef VISCOS_PLATFORM_WINDOWS
			ReleaseDC(static_cast<HWND>(m_NativeWindow), m_Device);
#endif
			throw ViscosException("Failed to load WGL functions!");
		}

		// Enable V-Sync
		// TODO: Abstract V-Sync system
		if (GLAD_WGL_EXT_swap_control && wglSwapIntervalEXT)
		{
			if (!wglSwapIntervalEXT(1))
				VSCS_CORE_WARN("Failed to enable VSync!");
		}
		else
		{
			VSCS_CORE_WARN("WGL swap control is not supported!");
		}

		// Enable alpha blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		VSCS_CORE_TRACE("OpenGL context created!");
		VSCS_CORE_TRACE("OpenGL Version: {}.{}", GLVersion.major, GLVersion.minor);

		s_TargetAPI = GraphicsAPI::OpenGL;
	}

	OpenGLGraphics::~OpenGLGraphics()
	{
		if (m_Context)
		{
			if (wglGetCurrentContext() == m_Context)
				wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(m_Context);
			m_Context = nullptr;
		}

#ifdef VISCOS_PLATFORM_WINDOWS
		if (m_Device)
		{
			ReleaseDC(static_cast<HWND>(m_NativeWindow), m_Device);
			m_Device = nullptr;
		}
#endif
	}

	void OpenGLGraphics::Present()
	{
#ifdef VISCOS_PLATFORM_WINDOWS
		if (SwapBuffers(m_Device) == FALSE)
		{
			throw ViscosException("Failed to swap framebuffers!");
		}
#endif
	}

}
