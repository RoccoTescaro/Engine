#include "pch.h"
#include "WindowsInput.h"
#include <GLFW/glfw3.h>
#include "Engine/Application.h"


namespace Engine 
{
	Input* Input::instance = new WindowsInput();

	bool WindowsInput::isKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetKey(window, keycode);
		
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::isMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}
	std::pair<float, float> WindowsInput::getMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return std::pair<float, float>(xPos, yPos);
	}

	float WindowsInput::getMouseXImpl()
	{
		return getMousePositionImpl().first;
	}

	float WindowsInput::getMouseYImpl()
	{
		return getMousePositionImpl().second;
	}
}