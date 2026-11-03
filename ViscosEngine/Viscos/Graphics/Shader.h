#pragma once

#include "Viscos/Core/API.h"

#include <memory>
#include <filesystem>

namespace Viscos {

	class VISCOS_API Shader
	{
	public:
		enum class Stage
		{
			Vertex, Pixel
		};

		Shader(const Shader&) = delete;
		Shader& operator=(const Shader&) = delete;
		virtual ~Shader() = default;

		Stage GetStage() const noexcept
		{
			return m_Stage;
		}

		static std::shared_ptr<Shader> CreateFromFile(Stage stage, const std::filesystem::path& path);

	protected:
		explicit Shader(Stage stage) noexcept : m_Stage(stage) { }
		Stage m_Stage;
	};

}
