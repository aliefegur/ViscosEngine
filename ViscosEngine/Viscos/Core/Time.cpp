#include "Time.h"

namespace Viscos {

	Time::Clock::time_point Time::s_StartTime;
	Time::Clock::time_point Time::s_LastFrameTime;

	float Time::s_DeltaTime = 0.0f;
	double Time::s_ElapsedTime = 0.0;

	void Time::Init()
	{
		const auto current = Clock::now();

		s_StartTime = current;
		s_LastFrameTime = current;

		s_DeltaTime = 0.0f;
		s_ElapsedTime = 0.0f;
	}

	void Time::Update()
	{
		const auto current = Clock::now();

		s_DeltaTime = std::chrono::duration<float>(current - s_LastFrameTime).count();
		s_ElapsedTime = std::chrono::duration<double>(current - s_StartTime).count();

		s_LastFrameTime = current;
	}

	double Time::ElapsedTime()
	{
		return s_ElapsedTime;
	}

	float Time::DeltaTime()
	{
		return s_DeltaTime;
	}

}
