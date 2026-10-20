#include "VertexInput.h"
#include "Graphics.h"
#include "Viscos/Core/Log.h"
#include "Viscos/Platform/OpenGL/OpenGLVertexInput.h"

namespace Viscos {

	std::unique_ptr<VertexInput> VertexInput::Create()
	{
		switch (Graphics::GetAPI())
		{
		case GraphicsAPI::None:
			VSCS_CORE_ERROR("Failed to create Vertex Input: current GraphicsAPI is NONE!");
			break;
		case GraphicsAPI::OpenGL:
			return std::make_unique<OpenGLVertexInput>();
		case GraphicsAPI::D3D11:
			VSCS_CORE_ERROR("Failed to create Vertex Input: currently Viscos Engine does not support Direct3D 11!");
			break;
		case GraphicsAPI::D3D12:
			VSCS_CORE_ERROR("Failed to create Vertex Input: currently Viscos Engine does not support Direct3D 12!");
			break;
		case GraphicsAPI::Vulkan:
			VSCS_CORE_ERROR("Failed to create Vertex Input: currently Viscos Engine does not support Vulkan!");
			break;
		}

		return nullptr;
	}

}
