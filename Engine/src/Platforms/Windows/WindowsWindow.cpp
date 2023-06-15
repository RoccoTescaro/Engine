#include "pch.h"
#include "WindowsWindow.h"
#include "Engine/Log.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Engine 
{

	static bool glfwInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::init(const WindowProps& props)
	{
		data.title = props.title;
		data.width = props.width;
		data.height = props.height;

		CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!glfwInitialized)
		{
			int success = glfwInit();
			CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);

			glfwInitialized = true;
		}

		window = glfwCreateWindow((int)props.width, (int)props.height, data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CORE_ASSERT(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(window, &data);
		setVSync(true);

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;
				WindowResize event(width, height);
				data.eventCallBack(event);
			});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowClose event;
				data.eventCallBack(event);
			});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressed event(key, 0);
					data.eventCallBack(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleased event(key);
					data.eventCallBack(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressed event(key, 1);
					data.eventCallBack(event);
					break;
				}
				}
			});	

		glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int character) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				KeyTyped event(character);
				data.eventCallBack(event);
			});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressed event(button);
					data.eventCallBack(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleased event(button);
					data.eventCallBack(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xoff, double yoff) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolled event((float)xoff, (float)yoff);
				data.eventCallBack(event);
			});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMoved event((float)xpos, (float)ypos);
				data.eventCallBack(event);
			});
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(window);
	}

	void WindowsWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WindowsWindow::setVSync(bool enable)
	{
		if (enable)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.vSync = enable;
	}

	bool WindowsWindow::isVSync() const
	{
		return data.vSync;
	}

}
