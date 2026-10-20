#pragma once

#include "Viscos/Graphics/VertexInput.h"

#include <glad/glad.h>

namespace Viscos {

	class OpenGLVertexInput : public VertexInput
	{
	public:
		OpenGLVertexInput();
		~OpenGLVertexInput() override;

		void AddVertexBuffer(VertexBuffer& buffer, VertexBufferLayout& layout) override;
		void SetIndexBuffer(IndexBuffer& buffer) override;

		void Bind() override;

	private:
		GLuint m_VAO;
		GLuint m_NextAttributeIndex = 0;
	};

}
