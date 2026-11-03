#pragma once

#include "API.h"
#include "ApplicationSpecification.h"
#include "Layer.h"
#include "LayerStack.h"
#include "Window.h"

namespace Viscos {

	class Application 
	{
	public:
		VISCOS_API Application(const ApplicationSpecification& appSpec = {});
		virtual VISCOS_API ~Application();

		VISCOS_API void Run();

		VISCOS_API void OnEvent(Event& e);

		VISCOS_API void PushLayer(std::unique_ptr<Layer> layer);
		VISCOS_API void PushOverlay(std::unique_ptr<Layer> overlay);

	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
	};

}
