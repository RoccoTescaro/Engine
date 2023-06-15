#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Window.h"

namespace Engine 
{

	class API Application 
	{
	public:
		Application();

		virtual ~Application();

		inline static Application& get() { return *instance; }

		inline Window& getWindow() { return *window; }

		void run();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		void onEvent(Event& e);
	private:
		bool onWindowClose(WindowClose& e);

		std::unique_ptr<Window> window;
		bool running = true;
		LayerStack layerStack;

		static Application* instance;
	};

	Application* createApplication();

}