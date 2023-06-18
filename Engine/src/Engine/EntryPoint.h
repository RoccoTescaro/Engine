#pragma once
#include "Application.h"
#include "Imgui/ImguiLayer.h"

#ifdef PLATFORM_WINDOWS

int main(int argc, char** argv) 
{
	Engine::Application::init();
	auto& app = Engine::Application::get();
	app.setImguiLayer(new Engine::ImguiLayer());
	app.run();
}

#endif