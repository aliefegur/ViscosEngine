#pragma once

#include "Viscos/Core/Input/InputProvider.h"

#include <bitset>

namespace Viscos {

	class Win32Input final : public InputProvider
	{
	public:
		Win32Input() = default;
		~Win32Input() override = default;

		bool IsKeyPressed(KeyCode key) const override;
		void SetKeyState(KeyCode key, bool pressed);

		static KeyCode TranslateKeyCode(uint32_t virtualKey);

	private:
		std::bitset<KeyCodeCount> m_KeyStates;
	};

}
