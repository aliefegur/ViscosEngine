#include "Event.h"

namespace Viscos {

	
	std::string Event::ToString() const
	{
		return GetName();
	}

	bool Event::IsInCategory(EventCategory category) const
	{
		return GetCategoryFlags() & static_cast<int>(category);
	}

}
