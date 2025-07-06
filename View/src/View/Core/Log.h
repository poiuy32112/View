#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace View
{
	class VIEW_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

// Core log macros
#define VI_CORE_TRACE(...)	::View::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VI_CORE_INFO(...)	::View::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VI_CORE_WARN(...)	::View::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VI_CORE_ERROR(...)	::View::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VI_CORE_FATAL(...)	::View::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VI_TRACE(...)	::View::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VI_INFO(...)	::View::Log::GetClientLogger()->info(__VA_ARGS__)
#define VI_WARN(...)	::View::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VI_ERROR(...)	::View::Log::GetClientLogger()->error(__VA_ARGS__)
#define VI_FATAL(...)	::View::Log::GetClientLogger()->fatal(__VA_ARGS__)

}


