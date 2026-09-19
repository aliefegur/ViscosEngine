#pragma once

#include "Viscos/Core/API.h"
#include "KeyCode.h"

namespace Viscos {

	class InputProvider;

	class VISCOS_API Input
	{
		friend class Application;
	public:
		static bool IsKeyPressed(KeyCode key) noexcept;
	private:
		static void SetKeyPressed(KeyCode key, bool pressed) noexcept;
	};

}
