#pragma once
#include "Engine/Window.h"
#include "GLFW/glfw3.h"

namespace Engine 
{
	
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline uint16_t getWidth() const override { return data.width; }

		inline uint16_t getHeight() const override { return data.height; }

		inline void setEventCallBack(const EventCallBack& func) override { data.eventCallBack = func; }

		void setVSync(bool enable) override;

		bool isVSync() const override;

		inline virtual void* getNativeWindow() const override { return window; }
	private:
		virtual void init(const WindowProps& props);
		
		virtual void shutdown();
	
		GLFWwindow* window;
		
		struct WindowData
		{
			std::string title;
			uint16_t width, height;
			bool vSync;
			EventCallBack eventCallBack;
		};

		WindowData data;
	};

}