#pragma once

#include "API.h"
#include "Viscos/Events/Event.h"

#include <string>

namespace Viscos {

	class VISCOS_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") : m_Name(name) { };
		virtual ~Layer() = default;

		virtual void OnAttach() { }
		virtual void OnDetach() { }
		virtual void OnUpdate() { }
		virtual void OnEvent(Event& e) { }
		virtual void OnRender() { }

		const std::string& GetName() const { return m_Name; }

	private:
		std::string m_Name;
	};

	class VISCOS_API Overlay : public Layer
	{
	public:
		Overlay(const std::string& name = "Overlay") : Layer(name) { }
		~Overlay() override = default;
	};

}
