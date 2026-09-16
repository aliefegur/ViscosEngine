#pragma once

#include "KeyCode.h"

namespace Viscos {
	
	class InputProvider
	{
	public:
		virtual ~InputProvider() = default;
		virtual bool IsKeyPressed(KeyCode key) const = 0;
	};

}
