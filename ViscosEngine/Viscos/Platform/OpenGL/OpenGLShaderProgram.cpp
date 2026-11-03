#include "OpenGLShader.h"
#include "OpenGLShaderProgram.h"
#include "Viscos/Core/Log.h"

namespace Viscos {

	namespace {

		std::string GetProgramLinkLog(GLuint program)
		{
			GLint length = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

			if (length <= 1)
				return "OpenGL returned no link log.";

			std::string log(static_cast<size_t>(length), '\0');
			GLsizei written = 0;

			glGetProgramInfoLog(program, length, &written, log.data());
			log.resize(static_cast<size_t>(written));

			return log;
		}

	}

	Viscos::OpenGLShaderProgram::~OpenGLShaderProgram()
	{
		if (m_ShaderProgram)
			glDeleteProgram(m_ShaderProgram);
	}

	OpenGLShaderProgram::OpenGLShaderProgram()
		: m_ShaderProgram(glCreateProgram())
	{
	}

	void OpenGLShaderProgram::Attach(const std::shared_ptr<Shader>& shader)
	{
		if (m_Linked) 
		{
			VSCS_CORE_WARN("Cannot attach a shader after linking.");
			return;
		}

		if (!shader)
		{
			VSCS_CORE_ERROR("Cannot attach a null shader.");
			return;
		}

		auto glShader = std::dynamic_pointer_cast<OpenGLShader>(shader);

		if (!glShader)
		{
			VSCS_CORE_ERROR("Expected an OpenGL shader.");
			return;
		}

		if (HasStage(glShader->GetStage()))
		{
			// TODO: These warnings could be prettier.
			VSCS_CORE_WARN("A shader for this stage is already attached.");
			return;
		}
		
		m_Shaders.push_back(glShader);
		glAttachShader(m_ShaderProgram, *glShader);
	}

	void OpenGLShaderProgram::Link()
	{
		if (m_Linked)
			return;

		if (!HasStage(Shader::Stage::Vertex) || !HasStage(Shader::Stage::Pixel))
		{
			VSCS_CORE_ERROR("Linking requires a vertex and a pixel shader.");
			return;
		}

		glLinkProgram(m_ShaderProgram);

		GLint isLinked = GL_FALSE;
		glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &isLinked);

		if (isLinked != GL_TRUE)
		{
			VSCS_CORE_ERROR("Shader program link failed:\n{}", GetProgramLinkLog(m_ShaderProgram));
			return;
		}

		m_Linked = true;
	}

	void OpenGLShaderProgram::Bind() const
	{
		if (!m_Linked)
		{
			VSCS_CORE_ERROR("Link the shader program before binding it.");
			return;
		}

		glUseProgram(m_ShaderProgram);
	}

	bool OpenGLShaderProgram::HasStage(Shader::Stage stage) const
	{
		return std::any_of(m_Shaders.begin(), m_Shaders.end(),
			[stage](const auto& shader) 
			{
				return shader->GetStage() == stage;
			});
	}

}
