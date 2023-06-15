#include "pch.h"
#include "Layer.h"

namespace Engine
{
	uint8_t Layer::layerN = 0;

	Layer::Layer()
	{
		debugName = "Layer" + std::to_string(Layer::layerN++);
	}

	Layer::Layer(const std::string& name)
		: debugName(name)
	{
	}

	Layer::~Layer()
	{
		Layer::layerN--;
	}
}
