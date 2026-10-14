#include "IndexBuffer.h"
#include "Graphics.h"
#include "Viscos/Core/Log.h"
#include "Viscos/Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Viscos {

	IndexBuffer::IndexBuffer(Usage u, Type t) : Buffer(u), m_Type(t)
	{
	}

	IndexBuffer::Type IndexBuffer::GetType() const
	{
		return m_Type;
	}

	size_t IndexBuffer::GetIndexSize() const
	{
		switch (m_Type)
		{
		case Viscos::IndexBuffer::Type::Uint16:
			return 2;
		case Viscos::IndexBuffer::Type::Uint32:
			return 4;
		}
	}

	std::unique_ptr<IndexBuffer> IndexBuffer::Create(const void* data, size_t size, Usage u, Type t)
	{
		switch (Graphics::GetAPI())
		{
		case GraphicsAPI::None:
			VSCS_CORE_ERROR("Failed to create index buffer: current GraphicsAPI is NONE!");
			break;
		case GraphicsAPI::OpenGL:
			return std::make_unique<OpenGLIndexBuffer>(data, size, u, t);
		case GraphicsAPI::D3D11:
			VSCS_CORE_ERROR("Failed to create index buffer: currently Viscos Engine does not support Direct3D 11!");
			break;
		case GraphicsAPI::D3D12:
			VSCS_CORE_ERROR("Failed to create index buffer: currently Viscos Engine does not support Direct3D 12!");
			break;
		case GraphicsAPI::Vulkan:
			VSCS_CORE_ERROR("Failed to create index buffer: currently Viscos Engine does not support Vulkan!");
			break;
		}

		return nullptr;
	}

}
