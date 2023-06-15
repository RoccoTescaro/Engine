#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Engine
{
	class API Layer
	{
	public:
		Layer();
		Layer(const std::string& name);
	
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onImGuiRender() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return debugName; }
		inline static uint8_t getLayerN() { return layerN; }
	protected:
		std::string debugName;
	private:
		static uint8_t layerN;
	};
}

