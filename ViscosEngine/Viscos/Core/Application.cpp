#include "Application.h"

#include "Log.h"

namespace Viscos {

	Application::Application()
	{
		Log::Initialize();

		// TODO: Implement Application Specification system!
		m_Window = Window::Create({ "Viscos Engine", 1280, 720 });
		m_Window->SetEventCallback(
			[this](Event& e) 
			{
				OnEvent(e);
			});
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
			m_LayerStack.OnUpdate();
			m_LayerStack.OnRender();
		}
	}

	void Application::OnEvent(Event& e)
	{
		if (e.GetEventType() == EventType::WindowClose)
		{
			m_Running = false;
		}

		m_LayerStack.OnEvent(e);
	}

	void Application::PushLayer(std::unique_ptr<Layer> layer)
	{
		m_LayerStack.PushLayer(std::move(layer));
	}

	void Application::PushOverlay(std::unique_ptr<Layer> overlay)
	{
		m_LayerStack.PushOverlay(std::move(overlay));
	}

}
