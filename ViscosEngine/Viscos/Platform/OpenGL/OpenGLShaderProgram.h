#pragma once

#include "Viscos/Graphics/ShaderProgram.h"
#include "OpenGLShader.h"

#include <vector>
#include <memory>

namespace Viscos {

	class OpenGLShaderProgram : public ShaderProgram
	{
	public:
		OpenGLShaderProgram();
		~OpenGLShaderProgram() override;

		void Attach(const std::shared_ptr<Shader>& shader) override;
		void Link() override;
		
		void Bind() const override;

	private:
		GLuint m_ShaderProgram;
		bool m_Linked = false;
		std::vector<std::shared_ptr<OpenGLShader>> m_Shaders;

		bool HasStage(Shader::Stage stage) const;
	};

}
