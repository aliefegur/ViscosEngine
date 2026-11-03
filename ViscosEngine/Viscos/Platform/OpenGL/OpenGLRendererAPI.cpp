#include "OpenGLRendererAPI.h"
#include "OpenGLIndexBuffer.h"

#include <glad/glad.h>

namespace Viscos {
	
	void OpenGLRendererAPI::Clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const VertexInput& input)
	{
		const auto& indexBuffer = input.GetIndexBuffer();
		const auto count = indexBuffer.GetCount();
		constexpr auto maxCount = static_cast<size_t>((std::numeric_limits<GLsizei>::max)());

		if (count > maxCount)
		{
			VSCS_CORE_ERROR("Index count {} exceeds OpenGL limit {}!", count, maxCount);
			return;
		}

		glDrawElements(
			GL_TRIANGLES,
			static_cast<GLsizei>(count),
			OpenGLIndexBuffer::TranslateType(indexBuffer.GetType()),
			nullptr
		);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

}
