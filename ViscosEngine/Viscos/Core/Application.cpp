#include "Application.h"

#include "Log.h"
#include "Time.h"
#include "Viscos/Events/KeyEvents.h"
#include "Viscos/Input/Input.h"

namespace Viscos {

	Application::Application(const ApplicationSpecification& appSpec)
	{
		Log::Initialize();

		m_Window = Window::Create({ 
			appSpec.Name, 
			appSpec.Width, 
			appSpec.Height 
		});
		
		m_Window->SetEventCallback(
			[this](Event& e) 
			{
				OnEvent(e);
			});
	}

	void Application::Run()
	{
		Time::Init();

		while (m_Running)
		{
			Time::Update();

			m_Window->OnUpdate();
			m_LayerStack.OnUpdate();
			m_LayerStack.OnRender();
		}
	}

	void Application::OnEvent(Event& e)
	{
		// Event type & category
		const auto type = e.GetEventType();
		const auto categoryFlags = e.GetCategoryFlags();

		// Window close event
		if (type == EventType::WindowClose)
		{
			m_Running = false;
		}

		// Key events
		if (categoryFlags & (EventCategoryInput | EventCategoryKeyboard))
		{
			const KeyEvent& event = static_cast<KeyEvent&>(e);
			const auto keyCode = event.GetKeyCode();

			switch (type)
			{
			case EventType::KeyPressed:
				Input::SetKeyPressed(keyCode, true);
				break;
			case EventType::KeyReleased:
				Input::SetKeyPressed(keyCode, false);
				break;
			default:
				VSCS_CORE_WARN("Event Category & Type mismatch! ({}), Category Flags: {}, Type: {}", e.ToString(), e.GetCategoryFlags(), static_cast<int>(e.GetEventType()));
				break;
			}
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
