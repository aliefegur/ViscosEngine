#include "Window.h"

#include "Viscos/Core/Log.h"

#ifdef VISCOS_PLATFORM_WINDOWS
#include "Viscos/Platform/Windows/Win32Window.h"
#endif

namespace Viscos {

	void Window::SetEventCallback(const EventCallbackFn& callback)
	{
		m_EventCallback = std::move(callback);
	}

	std::unique_ptr<Window> Window::Create(const WindowProperties& p)
	{
#ifdef VISCOS_PLATFORM_WINDOWS
		return std::make_unique<Win32Window>(p);
#else
		VSCS_CORE_ERROR("ViscosEngine cannot create window for this platform!");
		return nullptr;
#endif
	}

}
