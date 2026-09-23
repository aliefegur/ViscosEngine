#include "Time.h"

namespace Viscos {

	Time::Clock::time_point Time::s_StartTime;
	Time::Clock::time_point Time::s_LastFrameTime;

	float Time::s_DeltaTime = 0.0f;
	double Time::s_ElapsedTime = 0.0;

	float Time::s_FPS = 0.0f;
	float Time::s_FPSTimer = 0.0f;
	uint32_t Time::s_FPSFrameCount = 0;

	void Time::Init() noexcept
	{
		const auto current = Clock::now();

		s_StartTime = current;
		s_LastFrameTime = current;

		s_DeltaTime = 0.0f;
		s_ElapsedTime = 0.0f;

		s_FPS = 0.0f;
		s_FPSTimer = 0.0f;
		s_FPSFrameCount = 0;
	}

	void Time::Update() noexcept
	{
		const auto current = Clock::now();

		s_DeltaTime = std::chrono::duration<float>(current - s_LastFrameTime).count();
		s_ElapsedTime = std::chrono::duration<double>(current - s_StartTime).count();

		s_LastFrameTime = current;

		// FPS Measurement
		s_FPSTimer += s_DeltaTime;
		++s_FPSFrameCount;

		constexpr float FPS_MEASUREMENT_INTERVAL = 0.5f;
		
		if (s_FPSTimer >= FPS_MEASUREMENT_INTERVAL)
		{
			s_FPS = static_cast<float>(s_FPSFrameCount) / s_FPSTimer;

			s_FPSTimer = 0.0f;
			s_FPSFrameCount = 0;
		}
	}

	double Time::ElapsedTime() noexcept
	{
		return s_ElapsedTime;
	}

	float Time::DeltaTime() noexcept
	{
		return s_DeltaTime;
	}

	float Time::FPS() noexcept
	{
		return s_FPS;
	}

}
