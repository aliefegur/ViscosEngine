#include "Event.h"

namespace Viscos {

	
	std::string Event::ToString() const noexcept
	{
		return GetName();
	}

	bool Event::IsInCategory(EventCategory category) const noexcept
	{
		return GetCategoryFlags() & static_cast<int>(category);
	}

}
