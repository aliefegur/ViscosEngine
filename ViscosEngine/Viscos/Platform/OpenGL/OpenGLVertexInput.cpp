#include "OpenGLVertexInput.h"

namespace Viscos {

	OpenGLVertexInput::OpenGLVertexInput()
	{
		glCreateVertexArrays(1, &m_VAO);
	}

	OpenGLVertexInput::~OpenGLVertexInput()
	{
		glDeleteVertexArrays(1, &m_VAO);
		m_VAO = NULL;
	}

	void OpenGLVertexInput::AddVertexBuffer(VertexBuffer& buffer, VertexBufferLayout& layout)
	{
		Bind();
		buffer.Bind();
		
		// Vertex attributes
		for (const auto& attrib : layout.GetAttributes())
		{
			GLenum type;
			switch (attrib.Type)
			{
			case VertexAttribute::Type::Float32: type = GL_FLOAT; break;
			case VertexAttribute::Type::Int32: type = GL_INT; break;
			case VertexAttribute::Type::UInt32: type = GL_UNSIGNED_INT; break;
			case VertexAttribute::Type::Int16: type = GL_SHORT; break;
			case VertexAttribute::Type::UInt16: type = GL_UNSIGNED_SHORT; break;
			case VertexAttribute::Type::Int8: type = GL_BYTE; break;
			case VertexAttribute::Type::UInt8: type = GL_UNSIGNED_BYTE; break;
			}

			if (attrib.Type == VertexAttribute::Type::Float32 || attrib.Normalized)
			{
				glVertexAttribPointer(
					m_NextAttributeIndex,
					attrib.ComponentCount,
					type,
					attrib.Normalized ? GL_TRUE : GL_FALSE,
					static_cast<GLsizei>(layout.GetStride()),
					reinterpret_cast<const void*>(attrib.Offset)
				);
			}
			else
			{
				glVertexAttribIPointer(
					m_NextAttributeIndex,
					attrib.ComponentCount,
					type,
					static_cast<GLsizei>(layout.GetStride()),
					reinterpret_cast<const void*>(attrib.Offset)
				);
			}

			glEnableVertexAttribArray(m_NextAttributeIndex++);
		}
	}

	void OpenGLVertexInput::SetIndexBuffer(IndexBuffer& buffer)
	{
		Bind();
		buffer.Bind();
	}

	void OpenGLVertexInput::Bind()
	{
		glBindVertexArray(m_VAO);
	}

}
