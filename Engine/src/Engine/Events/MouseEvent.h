#pragma once

#include "Event.h"

namespace Engine 
{
	
	class API MouseMoved : public Event
	{
	public:
		MouseMoved(float x, float y) : x(x), y(y) {}

		inline float getX() const { return x; }

		inline float getY() const { return y; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved: " << x << ", " << y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)

		EVENT_CLASS_CATEGORY(Mouse | Input)
	private:
		float x, y;
	};

	class API MouseScrolled : public Event
	{
	public:
		MouseScrolled(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset) {}

		inline float getXOffset() const { return xOffset; }

		inline float getYOffset() const { return yOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled: " << xOffset << ", " << yOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)

		EVENT_CLASS_CATEGORY(Mouse | Input)
	private:
		float xOffset, yOffset;
	};

	class API MouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(MouseButton | Mouse | Input)
	protected:
		MouseButtonEvent(uint8_t button) : button(button) {}

		uint8_t button;
	};

	class API MouseButtonPressed : public MouseButtonEvent
	{
	public:
		MouseButtonPressed(uint8_t button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << (int)button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class API MouseButtonReleased : public MouseButtonEvent
	{
	public:
		MouseButtonReleased(uint8_t button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased: " << (int)button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}