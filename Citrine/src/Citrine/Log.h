#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Citrine {


	class CITRINE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Core log macros
#define CT_CORE_TRACE(...)    ::Citrine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CT_CORE_INFO(...)     ::Citrine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CT_CORE_WARN(...)     ::Citrine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CT_CORE_ERROR(...)    ::Citrine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CT_CORE_FATAL(...)    ::Citrine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CT_TRACE(...)         ::Citrine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CT_INFO(...)          ::Citrine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CT_WARN(...)          ::Citrine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CT_ERROR(...)         ::Citrine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CT_FATAL(...)         ::Citrine::Log::GetClientLogger()->fatal(__VA_ARGS__)