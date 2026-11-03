#include "Shader.h"
#include "Graphics.h"
#include "Viscos/Core/Log.h"
#include "Viscos/Platform/OpenGL/OpenGLShader.h"

namespace Viscos {

	std::shared_ptr<Shader> Shader::CreateFromFile(Stage stage, const std::filesystem::path& path)
	{
		std::ifstream file(path, std::ios::binary);

		if (!file.is_open())
		{
			VSCS_CORE_ERROR("Cannot open shader file: {}", path.string());
		}

		std::ostringstream contents;
		contents << file.rdbuf();

		if (file.bad() || contents.bad())
		{
			VSCS_CORE_ERROR("Cannot read shader file: {}", path.string());
		}

		const std::string source = contents.str();

		switch (Graphics::GetAPI())
		{
		case GraphicsAPI::OpenGL:
			return std::make_shared<OpenGLShader>(stage, source, path.string());
		case GraphicsAPI::D3D11:
			VSCS_CORE_ERROR("Failed to create shader object: Viscos Engine does not support D3D11!");
			return nullptr;
		case GraphicsAPI::D3D12:
			VSCS_CORE_ERROR("Failed to create shader object: Viscos Engine does not support D3D12!");
			return nullptr;
		case GraphicsAPI::Vulkan:
			VSCS_CORE_ERROR("Failed to create shader object: Viscos Engine does not support Vulkan!");
			return nullptr;
		}

		VSCS_CORE_ERROR("Failed to create shader object: Unsupported GraphicsAPI!");
		return nullptr;
	}

}
