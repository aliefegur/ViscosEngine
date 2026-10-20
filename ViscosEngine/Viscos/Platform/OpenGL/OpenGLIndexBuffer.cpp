#include "OpenGLIndexBuffer.h"

namespace Viscos {

	OpenGLIndexBuffer::OpenGLIndexBuffer(const void* data, size_t size, Usage u, Type t) : IndexBuffer(u, t)
	{
		glCreateBuffers(1, &m_EBO);
		Bind();
		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER,
			static_cast<GLsizeiptr>(size),
			data,
			u == Usage::Static ? GL_STATIC_DRAW
			: u == Usage::Dynamic ? GL_DYNAMIC_DRAW
			: NULL
		);

		m_Size = size;
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		if (m_EBO != 0)
			glDeleteBuffers(1, &m_EBO);
	}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	}

	void OpenGLIndexBuffer::SetData(const void* data, size_t size, size_t offset)
	{
		if (offset > m_Size || size > m_Size - offset)
		{
			VSCS_CORE_ERROR("OpenGLIndexBuffer::SetData: Write exceeds buffer capacity.");
		}

		if (offset % GetIndexSize() != 0 || size % GetIndexSize() != 0)
		{
			VSCS_CORE_ERROR("OpenGLIndexBuffer::SetData: Offset and size must be aligned to index type.");
		}

		if (size == 0) return;

		if (data == nullptr)
		{
			VSCS_CORE_WARN("OpenGLIndexBuffer::SetData: Data cannot be nullptr!");
		}

		Bind();

		glBufferSubData(
			GL_ELEMENT_ARRAY_BUFFER,
			static_cast<GLintptr>(offset),
			static_cast<GLsizeiptr>(size),
			data
		);
	}

}
