#pragma once

#include "Viscos/Graphics/IndexBuffer.h"
#include "Viscos/Core/Log.h"

#include <glad/glad.h>

namespace Viscos {

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(const void* data, size_t size, Usage u, Type t);
		~OpenGLIndexBuffer() override;

		void Bind() override;

		void SetData(const void* data, size_t size, size_t offset) override;


	private:
		GLuint m_EBO = 0;
	};

}
