#pragma once

#include "API.h"

#include <memory>
#include <spdlog/spdlog.h>

namespace Viscos {

	class VISCOS_API Log 
	{
	public:
		static void Initialize();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger()
        {
            return s_CoreLogger;
        }

        static std::shared_ptr<spdlog::logger>& GetClientLogger()
        {
            return s_ClientLogger;
        }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define VSCS_CORE_ERROR(...) ::Viscos::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VSCS_CORE_WARN(...) ::Viscos::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VSCS_CORE_INFO(...) ::Viscos::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VSCS_CORE_TRACE(...) ::Viscos::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define VSCS_ERROR(...) ::Viscos::Log::GetClientLogger()->error(__VA_ARGS__)
#define VSCS_WARN(...) ::Viscos::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VSCS_INFO(...) ::Viscos::Log::GetClientLogger()->info(__VA_ARGS__)
#define VSCS_TRACE(...) ::Viscos::Log::GetClientLogger()->trace(__VA_ARGS__)
