#include "pch.h"
#include "Application.h"
#include <glad/glad.h>

namespace Engine
{

	Application* Application::instance = nullptr;

	Application::Application()
	{
		CORE_ASSERT(!instance, "Application already exists!");
		instance = this;
		window = std::unique_ptr<Window>(Window::create());
		window->setEventCallBack(BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		while (running) 
		{
			
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0, 0.0, 0.0, 1.0);

			for (Layer* layer : layerStack)
				layer->onUpdate();

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
