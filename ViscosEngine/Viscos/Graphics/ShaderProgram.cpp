#include "ShaderProgram.h"
#include "Graphics.h"
#include "Viscos/Core/Log.h"
#include "Viscos/Platform/OpenGL/OpenGLShaderProgram.h"

namespace Viscos {

	std::unique_ptr<ShaderProgram> ShaderProgram::Create()
	{
		switch (Graphics::GetAPI())
		{
		case GraphicsAPI::OpenGL:
			return std::make_unique<OpenGLShaderProgram>();
		case GraphicsAPI::D3D11:
			VSCS_CORE_ERROR("Failed to create shader program: Viscos Engine does not support D3D11!");
			return nullptr;
		case GraphicsAPI::D3D12:
			VSCS_CORE_ERROR("Failed to create shader program: Viscos Engine does not support D3D12!");
			return nullptr;
		case GraphicsAPI::Vulkan:
			VSCS_CORE_ERROR("Failed to create shader program: Viscos Engine does not support Vulkan!");
			return nullptr;
		}
	}

}
