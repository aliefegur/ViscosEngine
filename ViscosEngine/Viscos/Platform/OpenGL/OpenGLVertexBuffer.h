#pragma once

#include "Viscos/Graphics/VertexBuffer.h"

#include <glad/glad.h>

namespace Viscos {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(const void* data, size_t size, Usage u);
		~OpenGLVertexBuffer() override;

		void Bind() override;

		void SetData(const void* data, size_t size, size_t offset) override;

	private:
		GLuint m_VBO;
	};

}
