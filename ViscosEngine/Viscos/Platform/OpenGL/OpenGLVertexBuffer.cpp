#include "OpenGLVertexBuffer.h"
#include "Viscos/Core/Log.h"

namespace Viscos {

	OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, size_t size, Usage u) : VertexBuffer(u)
	{
		glCreateBuffers(1, &m_VBO);
		Bind();
		glBufferData(
			GL_ARRAY_BUFFER, 
			static_cast<GLsizeiptr>(size), 
			data, 
			u == Usage::Static ? GL_STATIC_DRAW 
				: u == Usage::Dynamic ? GL_DYNAMIC_DRAW 
				: NULL);

		m_Size = size;
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		if (m_VBO != 0)
			glDeleteBuffers(1, &m_VBO);
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	}

	void OpenGLVertexBuffer::SetData(const void* data, size_t size, size_t offset)
	{
		if (offset > m_Size || size > m_Size - offset)
		{
			VSCS_CORE_ERROR("OpenGLVertexBuffer::SetData: Write exceeds buffer capacity.");
		}

		if (size == 0) return;

		if (data == nullptr)
		{
			VSCS_CORE_WARN("OpenGLVertexBuffer::SetData: Data cannot be nullptr!");
		}

		Bind();

		glBufferSubData(
			GL_ARRAY_BUFFER,
			static_cast<GLintptr>(offset),
			static_cast<GLsizeiptr>(size),
			data
		);
	}

}
