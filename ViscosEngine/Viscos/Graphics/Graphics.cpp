#include "Graphics.h"
#include "Viscos/Core/Window.h"
#include "Viscos/Core/Log.h"

#include "Viscos/Platform/OpenGL/OpenGLGraphics.h"

namespace Viscos {

	GraphicsAPI Graphics::s_TargetAPI = GraphicsAPI::None;

	Graphics::Graphics(const NativeHandle nativeWindow)
		: m_NativeWindow(nativeWindow)
	{
	}

	GraphicsAPI Graphics::GetAPI() noexcept
	{
		return s_TargetAPI;
	}

	std::unique_ptr<Graphics> Graphics::Create(GraphicsAPI api, NativeHandle nativeWindow)
	{
		switch (api)
		{
		case GraphicsAPI::None:
			VSCS_CORE_ERROR("No graphics API specified!");
			break;
		case GraphicsAPI::OpenGL:
			return std::make_unique<OpenGLGraphics>(nativeWindow);
		case GraphicsAPI::D3D11:
			VSCS_CORE_ERROR("Viscos Engine currently does not support D3D11!");
			break;
		case GraphicsAPI::D3D12:
			VSCS_CORE_ERROR("Viscos Engine currently does not support D3D12!");
			break;
		case GraphicsAPI::Vulkan:
			VSCS_CORE_ERROR("Viscos Engine currently does not support Vulkan!");
			break;
		}

		return nullptr;
	}

}
