#pragma once

#include "API.h"

#include <ctime>

namespace Viscos {

	class VISCOS_API Time
	{
		friend class Application;
	private:
		static void Init();
		static void Update();
	
	public:
		static double ElapsedTime();
		static float DeltaTime();

	private:
		using Clock = std::chrono::steady_clock;

		static Clock::time_point s_StartTime;
		static Clock::time_point s_LastFrameTime;

		static float s_DeltaTime;
		static double s_ElapsedTime;
	};

}
