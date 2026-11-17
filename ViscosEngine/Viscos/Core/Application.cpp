#include "Application.h"

#include "Log.h"
#include "Time.h"
#include "Viscos/Events/AppEvents.h"
#include "Viscos/Events/KeyEvents.h"
#include "Viscos/Events/WindowEvents.h"
#include "Viscos/Input/Input.h"
#include "Viscos/Graphics/Renderer.h"

namespace Viscos {

	Application::Application(const ApplicationSpecification& appSpec)
	{
		Log::Initialize();

		m_Window = Window::Create({ 
			appSpec.Name, 
			appSpec.Width, 
			appSpec.Height,
			appSpec.GraphicsBackend
		});
		
		m_Window->SetEventCallback(
			[this](Event& e) 
			{
				OnEvent(e);
			});

		Renderer::Initialize();
	}

	Application::~Application()
	{
		Renderer::Shutdown();
	}

	void Application::Run()
	{
		Time::Init();

		while (m_Running)
		{
			Time::Update();

			AppUpdateEvent updateEvent;
			AppRenderEvent renderEvent;
			
			OnEvent(updateEvent);
			OnEvent(renderEvent);

			m_Window->Present();
		}
	}

	void Application::OnEvent(Event& e)
	{
		// Gameloop events
		switch (e.GetEventType())
		{
		case EventType::AppUpdate:
			m_LayerStack.OnUpdate();
			break;

		case EventType::AppRender:
			m_LayerStack.OnRender();
			break;

		default:
			break;
		}

		EventDispatcher dispatcher(e);

		// Window close event
		dispatcher.Dispatch<WindowCloseEvent>(
			[this](WindowCloseEvent& event)
			{
				m_Running = false;
				return false;
			}
		);
		
		// TODO: Move this operation into Engine Layer
		// TODO: Use framebuffer size for viewport resize, not client dimensions!
		// Window resize event
		dispatcher.Dispatch<WindowResizeEvent>(
			[](WindowResizeEvent& event)
			{
				Renderer::SetViewport(0, 0, event.GetWidth(), event.GetHeight());
				return false;
			}
		);

		// Key pressed event
		dispatcher.Dispatch<KeyPressedEvent>(
			[](KeyPressedEvent& event)
			{
				Input::SetKeyPressed(event.GetKeyCode(), true);
				return false;
			}
		);

		// Key released event
		dispatcher.Dispatch<KeyReleasedEvent>(
			[](KeyReleasedEvent& event)
			{
				Input::SetKeyPressed(event.GetKeyCode(), false);
				return false;
			}
		);

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
