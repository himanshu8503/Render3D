#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Render3D
{
	class R3D_API Log
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
#define R3D_CORE_TRACE(...)    ::Render3D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define R3D_CORE_ERROR(...)    ::Render3D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define R3D_CORE_INFO(...)     ::Render3D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define R3D_CORE_WARN(...)     ::Render3D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define R3D_CORE_CRITICAL(...) ::Render3D::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define R3D_TRACE(...)         ::Render3D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define R3D_ERROR(...)         ::Render3D::Log::GetClientLogger()->error(__VA_ARGS__)
#define R3D_INFO(...)          ::Render3D::Log::GetClientLogger()->info(__VA_ARGS__)
#define R3D_WARN(...)          ::Render3D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define R3D_CRITICAL(...)      ::Render3D::Log::GetClientLogger()->critical(__VA_ARGS__)



