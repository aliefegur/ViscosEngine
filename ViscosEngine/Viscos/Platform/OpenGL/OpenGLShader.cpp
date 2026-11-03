#include "OpenGLShader.h"
#include "Viscos/Core/Log.h"

namespace Viscos {

	namespace {

		GLenum ToOpenGLStage(Shader::Stage stage)
		{
			switch (stage)
			{
			case Viscos::Shader::Stage::Vertex:
				return GL_VERTEX_SHADER;
			case Viscos::Shader::Stage::Pixel:
				return GL_FRAGMENT_SHADER;
			}

			VSCS_CORE_WARN("Unsupported shader stage!");
			return 0;
		}

		std::string GetCompileLog(GLuint shader)
		{
			GLint length = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

			if (length <= 1)
				return "OpenGL returned no compilation log.";

			std::string log(static_cast<size_t>(length), '\0');

			GLsizei written;
			glGetShaderInfoLog(shader, length, &written, log.data());

			log.resize(static_cast<size_t>(written));
			return log;
		}

	}

	OpenGLShader::OpenGLShader(Stage stage, const std::string& source, const std::string& debugName) 
		: Shader(stage)
	{
		m_Shader = glCreateShader(ToOpenGLStage(stage));

		if (m_Shader == 0) 
		{
			VSCS_CORE_ERROR("Failed to create OpenGL Shader: {}", debugName);
		}

		const GLchar* src = source.data();
		const GLint length = static_cast<GLint>(source.size());

		glShaderSource(m_Shader, 1, &src, &length);
		glCompileShader(m_Shader);

		GLint compiled;
		glad_glGetShaderiv(m_Shader, GL_COMPILE_STATUS, &compiled);

		if (!compiled)
		{
			VSCS_CORE_ERROR("Shader compilation failed!: {}\n{}", debugName, GetCompileLog(m_Shader));
			glDeleteShader(m_Shader);
			m_Shader = 0;
		}
	}

	OpenGLShader::~OpenGLShader()
	{
		if (m_Shader)
			glDeleteShader(m_Shader);
	}

	unsigned int OpenGLShader::GetHandle() const noexcept
	{
		return m_Shader;
	}

	OpenGLShader::operator unsigned int() const noexcept
	{
		return GetHandle();
	}

}
