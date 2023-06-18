#include <Engine.h>
#include "Imgui/imgui.h"
#include <glm/glm.hpp>

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

	void onImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
};

class SandBox : public Engine::Application
{
public:
	SandBox()
	{
		pushLayer(new ExampleLayer());
	}

	~SandBox()
	{
	}

};

SET_APPLICATION(SandBox);