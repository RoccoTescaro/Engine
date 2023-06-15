#include <Engine.h>

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void onUpdate() override
	{
	}

	void onEvent(Engine::Event& event) override
	{
	}
};

class SandBox : public Engine::Application
{
public:
	SandBox()
	{
		pushLayer(new ExampleLayer());
		pushOverlay(new Engine::ImguiLayer());
	}

	~SandBox()
	{
	}

};

Engine::Application* Engine::createApplication()
{
	return new SandBox();
}