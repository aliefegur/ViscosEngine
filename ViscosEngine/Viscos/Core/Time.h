#pragma once

#include "API.h"

#include <ctime>

namespace Viscos {

	class VISCOS_API Time
	{
		friend class Application;
	private:
		static void Init() noexcept;
		static void Update() noexcept;
	
	public:
		static double ElapsedTime() noexcept;
		static float DeltaTime() noexcept;
		static float FPS() noexcept;

	private:
		using Clock = std::chrono::steady_clock;

		static Clock::time_point s_StartTime;
		static Clock::time_point s_LastFrameTime;

		static float s_DeltaTime;
		static double s_ElapsedTime;
		
		static float s_FPS;
		static float s_FPSTimer;
		static uint32_t s_FPSFrameCount;
	};

}
