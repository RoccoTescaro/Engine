#pragma once

#include "Event.h"
#include <sstream>

namespace Engine 
{

	class API WindowResize : public Event
	{
	public:
		WindowResize(uint32_t width, uint32_t height) : width(width), height(height) {}

		inline uint32_t getWidth() const { return width; }
		
		inline uint32_t getHeight() const { return height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResize: " << width << ", " << height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
	
		EVENT_CLASS_CATEGORY(Application)
	private:
		uint32_t width, height;
	};
		
	class API WindowClose : public Event
	{
	public:
		WindowClose() {}

		EVENT_CLASS_TYPE(WindowClose)
	
		EVENT_CLASS_CATEGORY(Application)
	};

	class API ApplicationTick : public Event
	{
	public:
		ApplicationTick() {}

		EVENT_CLASS_TYPE(ApplicationTick)
	
		EVENT_CLASS_CATEGORY(Application)
	};

	class API ApplicationUpdate : public Event
	{
	public:
		ApplicationUpdate() {}

		EVENT_CLASS_TYPE(ApplicationUpdate)
	
		EVENT_CLASS_CATEGORY(Application)
	};

	class API ApplicationRender : public Event
	{
	public:
		ApplicationRender() {}

		EVENT_CLASS_TYPE(ApplicationRender)
	
		EVENT_CLASS_CATEGORY(Application)
	};
	
}