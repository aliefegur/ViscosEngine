#pragma once

#include "Event.h"

namespace Viscos {

	class VISCOS_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		std::string ToString() const noexcept override { return "AppUpdateEvent"; }

		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class VISCOS_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		std::string ToString() const noexcept override { return "AppRenderEvent"; }

		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

}
