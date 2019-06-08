#pragma once

#include "Core.h"
#include <spdlog.h>
#include "fmt/ostr.h"

namespace Gen
{ 
	class GEN_API Squak
	{
	public:
		static void Init();

		const inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		const inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;

	};
}

#ifdef GEN_DEBUG

#define SQUAK_CORE_TRACE(...)		::Gen::Squak::GetCoreLogger()->trace(__VA_ARGS__)
#define SQUAK_CORE_INFO(...)		::Gen::Squak::GetCoreLogger()->info(__VA_ARGS__)
#define SQUAK_CORE_WARNING(...)		::Gen::Squak::GetCoreLogger()->warn(__VA_ARGS__)
#define SQUAK_CORE_ERROR(...)		::Gen::Squak::GetCoreLogger()->error(__VA_ARGS__)
#define SQUAK_CORE_FATAL(...)		::Gen::Squak::GetCoreLogger()->fatal(__VA_ARGS__)

#define SQUAK_TRACE(...)			::Gen::Squak::GetClientLogger()->trace(__VA_ARGS__)
#define SQUAK_INFO(...)				::Gen::Squak::GetClientLogger()->info(__VA_ARGS__)
#define SQUAK_WARNING(...)			::Gen::Squak::GetClientLogger()->warn(__VA_ARGS__)
#define SQUAK_ERROR(...)			::Gen::Squak::GetClientLogger()->error(__VA_ARGS__)
#define SQUAK_FATAL(...)			::Gen::Squak::GetClientLogger()->fatal(__VA_ARGS__)
#endif

#ifndef GEN_DEBUG

#define SQUAK_CORE_TRACE
#define SQUAK_CORE_INFO
#define SQUAK_CORE_WARNING
#define SQUAK_CORE_ERROR
#define SQUAK_CORE_FATAL

#define SQUAK_TRACE
#define SQUAK_INFO
#define SQUAK_WARNING
#define SQUAK_ERROR
#define SQUAK_FATAL

#endif