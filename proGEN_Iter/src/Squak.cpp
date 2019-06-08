#include "GenPCH.h"
#include "Squak.h"
#include <spdlog.h>
#include <sinks/stdout_color_sinks.h>

namespace Gen
{
	std::shared_ptr <spdlog::logger> Squak::s_CoreLogger;
	std::shared_ptr <spdlog::logger> Squak::s_ClientLogger;

	void Squak::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stderr_color_mt("GEN");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::info);
	}
}