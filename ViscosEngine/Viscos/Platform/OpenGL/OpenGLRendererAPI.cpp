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
		glDrawElements(GL_TRIANGLES, input.GetIndexBuffer().GetCount(), OpenGLIndexBuffer::TranslateType(input.GetIndexBuffer().GetType()), nullptr);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

}
