#include "pch.h"
#include "LayerStack.h"

namespace Engine 
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : layers)
		{
			layer->onDetach();
			delete layer;
		}
	}

	void LayerStack::push(Layer* layer)
	{
		layers.emplace(layers.begin() + Layer::getLayerN(), layer);
		layer->onAttach();
	}

	void LayerStack::pushOverlay(Layer* overlay)
	{
		layers.emplace_back(overlay);
		overlay->onAttach();
	}

	void LayerStack::pop(Layer* layer)
	{
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end())
		{
			layer->onDetach();
			layers.erase(it);
		}
	}

	void LayerStack::popOverlay(Layer* overlay)
	{
		pop(overlay);
	}
}