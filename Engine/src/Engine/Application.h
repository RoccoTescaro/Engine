#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Window.h"
#include "Engine/Imgui/ImguiLayer.h"

namespace Engine 
{

	class API Application 
	{
	public:
		Application();
		virtual ~Application() = default;

		inline static Application& get() { return *instance; }
		static void init(); //defined client side with SET_APPLICATION macro
			
		inline void setImguiLayer(ImguiLayer* imguiLayer) { this->imguiLayer = imguiLayer; pushOverlay(imguiLayer); }

		inline Window& getWindow() { return *window; }

		void run();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		void onEvent(Event& e);
	protected:
		static Application* instance;
	private:
		bool onWindowClose(WindowClose& e);

		ImguiLayer* imguiLayer;
		std::unique_ptr<Window> window;
		bool running = true;
		LayerStack layerStack;
	};

}