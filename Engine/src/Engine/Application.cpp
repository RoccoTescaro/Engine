#include "pch.h"
#include "Application.h"
#include <glad/glad.h>
#include "Input.h"
#include "Log.h"

namespace Engine
{
	Application* Application::instance = nullptr;

	Application::Application()
	{
		Log::init(); 
		window = std::unique_ptr<Window>(Window::create()); 
		window->setEventCallBack(BIND_EVENT_FN(Application::onEvent)); 
	}

	void Application::run()
	{
		while (running) 
		{
			
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack)
				layer->onUpdate();

			imguiLayer->begin();
			for (Layer* layer : layerStack)
				layer->onImGuiRender();
			imguiLayer->end();

			window->onUpdate();
		};
	}

	void Application::pushLayer(Layer* layer)
	{
		layerStack.push(layer);
	}

	void Application::pushOverlay(Layer* overlay)
	{
		layerStack.pushOverlay(overlay);
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowClose>(BIND_EVENT_FN(Application::onWindowClose));

		for (auto it = layerStack.end(); it != layerStack.begin();)
		{
			(*--it)->onEvent(e);
			if (e.isHandled())
				break;
		}
	}

	bool Application::onWindowClose(WindowClose& e)
	{
		running = false;
		return true;
	}

}
