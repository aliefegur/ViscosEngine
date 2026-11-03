#pragma once

#include "Viscos/Graphics/Shader.h"

#include <string>

#include <glad/glad.h>

namespace Viscos {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(Stage stage, const std::string& source, const std::string& debugName);
		~OpenGLShader() override;

		unsigned int GetHandle() const noexcept;
		operator unsigned int() const noexcept;

	private:
		GLuint m_Shader;
	};

}
