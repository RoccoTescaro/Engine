#pragma once
#include "pch.h"
#include "Engine/Core.h"
#include "Engine/Events/Event.h"

namespace Engine 
{

	struct WindowProps
	{
		WindowProps(const std::string& title = "Engine", uint16_t width = 1280, uint16_t height = 720)
			: title(title), width(width), height(height)
		{
		}

		std::string title;
		uint16_t width;
		uint16_t height;
	};

	class API Window 
	{
	public:
		using EventCallBack = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void onUpdate() = 0;

		virtual uint16_t getWidth() const = 0;

		virtual uint16_t getHeight() const = 0;

		virtual void setEventCallBack(const EventCallBack& func) = 0;

		virtual void setVSync(bool enable) = 0;

		virtual bool isVSync() const = 0;
	
		static Window* create(const WindowProps& props = WindowProps());
	};

}