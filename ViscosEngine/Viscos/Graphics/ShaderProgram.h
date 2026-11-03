#pragma once

#include "Viscos/Core/API.h"
#include "Shader.h"

namespace Viscos {

	class VISCOS_API ShaderProgram
	{
	public:
		virtual ~ShaderProgram() = default;

		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;

		virtual void Attach(const std::shared_ptr<Shader>& shader) = 0;
		virtual void Link() = 0;

		virtual void Bind() const = 0;
		
		static std::unique_ptr<ShaderProgram> Create();

	protected:
		ShaderProgram() = default;
	};

}
