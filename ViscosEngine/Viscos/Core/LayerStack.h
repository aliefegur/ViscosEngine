#pragma once

#include "API.h"
#include "Layer.h"

#include <memory>
#include <vector>

namespace Viscos {

	class VISCOS_API LayerStack
	{
	public:
		using LayerContainer = std::vector<std::unique_ptr<Layer>>;
		using iterator = LayerContainer::iterator;
		using const_iterator = LayerContainer::const_iterator;

	public:
		LayerStack() = default;
		LayerStack(const LayerStack&) = delete;
		LayerStack& operator=(const LayerStack&) = delete;
		~LayerStack();

		void PushLayer(std::unique_ptr<Layer> layer);
		void PushOverlay(std::unique_ptr<Layer> overlay);

		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		void OnUpdate();
		void OnEvent(Event& e);
		void OnRender();

		iterator begin() { return m_Layers.begin(); }
		iterator end() { return m_Layers.end(); }
		const_iterator begin() const { return m_Layers.begin(); }
		const_iterator end() const { return m_Layers.end(); }

	private:
		LayerContainer m_Layers;
		size_t m_LayerInsertIndex = 0;
	};

}
