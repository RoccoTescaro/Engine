#pragma once

#ifdef PLATFORM_WINDOWS
	#if DDL //TODO remove completly in my version
		#ifdef BUILD_DLL  
			#define API __declspec(dllexport)
		#else
			#define API __declspec(dllimport)
		#endif
	#else
		#define API
	#endif
#else 
	#error Engine only supports Windows!
#endif

#ifdef ENABLE_ASSERT
#define CORE_ASSERT(x, ...) { if(!(x)) { CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ASSERT(x, ...) { if(!(x)) { ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define CORE_ASSERT(x, ...)
#define ASSERT(x, ...)
#endif


#define SET_APPLICATION(x, ...) \
		void Engine::Application::init()\
			{\
				CORE_ASSERT(!instance,"Application already istantiated");\
				instance = new x(__VA_ARGS__);\
			}

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)