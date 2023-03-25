#pragma once
#include "Engine/Core.h"
#include <typeinfo>
#include <string>

namespace Engine 
{

	class API Event
	{
	private:
		friend class EventDispatcher;
	public:
		enum class Type 
		{
			None = 0,
			
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			ApplicationTick, ApplicationUpdate, ApplicationRender,

			KeyPressed, KeyReleased, KeyTyped,
			
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
		};

		enum Category //max 32 categories
		{
			None = 0,
			Application = BIT(1),
			Input = BIT(2),
			Keyboard = BIT(3),
			Mouse = BIT(4),
			MouseButton = BIT(5)
		};

		virtual Type getType() const = 0;
		
		virtual const char* getName() const = 0;

		virtual uint32_t getCategory() const = 0;

		virtual std::string toString() const { return getName(); } //for debug purpose

		inline bool hasCategory(Category category) const 
		{ 
			return getCategory() & category; 
		}
	private:
		bool handled = false;
	};

	#define EVENT_CLASS_TYPE(type) static Type getStaticType() { return Type::##type; }\
								   virtual Type getType() const override { return getStaticType(); }\
								   virtual const char* getName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual uint32_t getCategory() const override { return category; }

	class API EventDispatcher
	{
	private:
		template<typename Type>
		using func = std::function<bool(Type&)>;
	public:
		EventDispatcher(Event& event) : event(event) {}

		template<typename T, typename F>
		bool dispatch(const F& func)
		{
			if (event.getType() == T::getStaticType())
			{
				event.handled = func(*(T*)&event);
				return true;
			}
			return false;
		}
	private:
		Event& event;
	};

	inline std::ostream& operator<< (std::ostream& os, const Event& event) 
	{
		return os << event.toString();
	}

}