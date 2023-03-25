#pragma once

#include "Event.h"
#include <sstream>

namespace Engine 
{

	class API KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(Keyboard | Input)
	protected:
		KeyEvent(int keyCode) : keyCode(keyCode) {}

		uint16_t keyCode;
	};

	class API KeyPressed : public KeyEvent
	{
	public:
		KeyPressed(uint16_t keyCode, uint32_t repeatCount) : KeyEvent(keyCode), repeatCount(repeatCount) {}

		inline uint32_t getRepeatCount() const { return repeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		uint32_t repeatCount;
	};

	class API KeyReleased : public KeyEvent
	{
	public:
		KeyReleased(uint16_t keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}