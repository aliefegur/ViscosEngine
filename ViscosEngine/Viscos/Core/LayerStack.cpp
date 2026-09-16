#include "LayerStack.h"

namespace Viscos {

	LayerStack::~LayerStack()
	{
		for (auto it = m_Layers.rbegin(); it != m_Layers.rend(); ++it)
		{
			(*it)->OnDetach();
		}
	}

	void LayerStack::PushLayer(std::unique_ptr<Layer> layer)
	{
		layer->OnAttach();

		m_Layers.emplace(
			begin() + static_cast<std::ptrdiff_t>(m_LayerInsertIndex),
			std::move(layer)
		);

		++m_LayerInsertIndex;
	}

	void LayerStack::PushOverlay(std::unique_ptr<Layer> overlay)
	{
		overlay->OnAttach();
		m_Layers.emplace_back(std::move(overlay));
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find_if(
			begin(),
			begin() + static_cast<std::ptrdiff_t>(m_LayerInsertIndex),
			[layer](const std::unique_ptr<Layer>& current)
			{
				return current.get() == layer;
			}
		);

		if (it != begin() + static_cast<std::ptrdiff_t>(m_LayerInsertIndex))
		{
			(*it)->OnDetach();
			m_Layers.erase(it);
			--m_LayerInsertIndex;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find_if(
			begin() + static_cast<std::ptrdiff_t>(m_LayerInsertIndex),
			end(),
			[overlay](const std::unique_ptr<Layer>& current)
			{
				return current.get() == overlay;
			}
		);

		if (it != end())
		{
			(*it)->OnDetach();
			m_Layers.erase(it);
		}
	}

	void LayerStack::OnUpdate()
	{
		for (auto& l : m_Layers) 
		{
			l->OnUpdate();
		}
	}

	void LayerStack::OnEvent(Event& e)
	{
		// Iterate in revese order for events
		for (auto it = m_Layers.rbegin(); it != m_Layers.rend(); ++it)
		{
			(*it)->OnEvent(e);
			
			if (e.Handled) 
				break;
		}
	}

	void LayerStack::OnRender()
	{
		for (auto& l : m_Layers)
		{
			l->OnRender();
		}
	}

}
