#include "Input.h"

namespace Viscos {

	static std::bitset<KeyCodeCount> s_KeyStates;

	bool Input::IsKeyPressed(KeyCode key) noexcept
	{
		const auto index = static_cast<size_t>(key);

		if (index >= KeyCodeCount)
			return false;

		return s_KeyStates[index];
	}

	void Input::SetKeyPressed(KeyCode key, bool pressed) noexcept
	{
		const auto index = static_cast<size_t>(key);

		if (index >= KeyCodeCount)
			return;

		s_KeyStates[index] = pressed;
	}

}
