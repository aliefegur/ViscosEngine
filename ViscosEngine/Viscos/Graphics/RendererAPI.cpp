#include "RendererAPI.h"

#include "Graphics.h"
#include "Viscos/Core/Log.h"
#include "Viscos/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Viscos {

	RendererAPI* RendererAPI::Create()
	{
		switch (Graphics::GetAPI())
		{
		case GraphicsAPI::None:
			VSCS_CORE_ERROR("Failed to create RendererAPI: current GraphicsAPI is NONE!");
			break;
		case GraphicsAPI::OpenGL:
			return new OpenGLRendererAPI();
		case GraphicsAPI::D3D11:
			VSCS_CORE_ERROR("Failed to create RendererAPI: currently Viscos Engine does not support Direct3D 11!");
			break;
		case GraphicsAPI::D3D12:
			VSCS_CORE_ERROR("Failed to create RendererAPI: currently Viscos Engine does not support Direct3D 12!");
			break;
		case GraphicsAPI::Vulkan:
			VSCS_CORE_ERROR("Failed to create RendererAPI: currently Viscos Engine does not support Vulkan!");
			break;
		}

		return nullptr;
	}

}
