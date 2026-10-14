#include "Vertex.h"
#include "VertexBuffer.h"
#include "Graphics.h"
#include "Viscos/Core/Log.h"
#include "Viscos/Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Viscos {

	std::unique_ptr<VertexBuffer> Viscos::VertexBuffer::Create(const void* data, size_t size, Usage u)
	{
		switch (Graphics::GetAPI())
		{
		case GraphicsAPI::None:
			VSCS_CORE_ERROR("Failed to create Vertex buffer: current GraphicsAPI is NONE!");
			break;
		case GraphicsAPI::OpenGL:
			return std::make_unique<OpenGLVertexBuffer>(data, size, u);
		case GraphicsAPI::D3D11:
			VSCS_CORE_ERROR("Failed to create Vertex buffer: currently Viscos Engine does not support Direct3D 11!");
			break;
		case GraphicsAPI::D3D12:
			VSCS_CORE_ERROR("Failed to create Vertex buffer: currently Viscos Engine does not support Direct3D 12!");
			break;
		case GraphicsAPI::Vulkan:
			VSCS_CORE_ERROR("Failed to create Vertex buffer: currently Viscos Engine does not support Vulkan!");
			break;
		}

		return nullptr;
	}

}
