#pragma once
#include "Core.h"

namespace Engine 
{

	class API Application 
	{
	public:
		Application();

		virtual ~Application();

		void run();
	};

	Application* createApplication();

}