#pragma once

#include "Viscos/Core/API.h"
#include "KeyCode.h"

#include <memory>

namespace Viscos {

	class InputProvider;

	class VISCOS_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		
		static void SetProvider(InputProvider* provider);

	private:
		static InputProvider* s_Provider;
	};

}
