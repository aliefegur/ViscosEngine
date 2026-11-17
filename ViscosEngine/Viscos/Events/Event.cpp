#include "Event.h"

namespace Viscos {

	
	std::string Event::ToString() const noexcept
	{
		return GetName();
	}

	bool Event::IsHandled() const noexcept
	{
		return m_Handled;
	}

	void Event::Handle() noexcept
	{
		if (CanBeHandled()) m_Handled = true;
	}

	bool Event::IsInCategory(EventCategory category) const noexcept
	{
		return GetCategoryFlags() & static_cast<int>(category);
	}

	bool Event::CanBeHandled() const noexcept
	{
		return (GetCategoryFlags() & (EventCategoryApplication | EventCategoryWindow)) == 0;
	}

}
