#pragma once

#include "API.h"
#include "ApplicationSpecification.h"
#include "Layer.h"
#include "LayerStack.h"
#include "Window.h"

namespace Viscos {

	class VISCOS_API Application 
	{
	public:
		Application(const ApplicationSpecification& appSpec = {});
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(std::unique_ptr<Layer> layer);
		void PushOverlay(std::unique_ptr<Layer> overlay);

		void SetFrameRateLimit(uint32_t fps) noexcept;
		uint32_t GetFrameRateLimit() const noexcept;

	private:
		void LimitFrameRate();

	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
		uint32_t m_FrameRateLimit = 120;
	};

}
