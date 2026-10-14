#include "Renderer.h"

#include "RendererAPI.h"

namespace Viscos {

	static RendererAPI* s_RendererAPI = nullptr;

	void Renderer::Initialize()
	{
		s_RendererAPI = RendererAPI::Create();
	}

	void Renderer::Shutdown()
	{
		delete s_RendererAPI;
		s_RendererAPI = nullptr;
	}

	void Renderer::Clear(float red, float green, float blue, float alpha)
	{
		s_RendererAPI->Clear(red, green, blue, alpha);
	}

	void Renderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		s_RendererAPI->SetViewport(x, y, width, height);
	}

}
