#pragma once
#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Engine 
{
	
	class API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }

		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

#define CORE_TRACE(...) Engine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...) Engine::Log::getCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...) Engine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) Engine::Log::getCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) Engine::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define TRACE(...) Engine::Log::getClientLogger()->trace(__VA_ARGS__)
#define INFO(...) Engine::Log::getClientLogger()->info(__VA_ARGS__)
#define WARN(...) Engine::Log::getClientLogger()->warn(__VA_ARGS__)
#define ERROR(...) Engine::Log::getClientLogger()->error(__VA_ARGS__) //change name
#define FATAL(...) Engine::Log::getClientLogger()->fatal(__VA_ARGS__)
