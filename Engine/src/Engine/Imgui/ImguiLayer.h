#pragma once
#include "Engine/Layer.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace Engine 
{
	class API ImguiLayer : public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onUpdate() override;
		virtual void onEvent(Event& e) override;
		virtual void onImGuiRender() override;
	private:
		bool onMouseButtonPress(MouseButtonPressed& e);
		bool onMouseButtonRelease(MouseButtonReleased& e);
		bool onMouseScroll(MouseScrolled& e);
		bool onMouseMove(MouseMoved& e);
		bool onKeyRelease(KeyReleased& e);
		bool onKeyPress(KeyPressed& e);
		bool onKeyTyped(KeyTyped& e);
		bool onWindowResize(WindowResize& e);

		float lastFrameTime = 0.0f;
	};
}


