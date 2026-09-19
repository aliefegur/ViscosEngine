#pragma once

#include <cstdint>

namespace Viscos {

	enum class KeyCode : uint16_t
	{
		Unknown = 0,
		Space, Apostrophe, Comma, Minus, Period, Slash,
		D0, D1, D2, D3, D4, D5, D6, D7, D8, D9,
		Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
		NumDecimal, NumDivide, NumMultiply, NumSubtract, NumAdd, NumEnter,
		Semicolon, Equal,
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		LeftBracket, Backslash, RightBracket, GraveAccent,
		Escape, Enter, Tab, Backspace, Insert, Delete,
		Right, Left, Down, Up,
        PageUp, PageDown, Home, End,
        CapsLock, ScrollLock, NumLock,
        PrintScreen, Pause,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        LeftShift, LeftControl, LeftAlt, LeftSuper,
        RightShift, RightControl, RightAlt, RightSuper,
        Menu,
		OEM8, OEM102,
		Count
	};

	constexpr size_t KeyCodeCount = static_cast<size_t>(KeyCode::Count);

	std::string KeyCodeToString(KeyCode keyCode) noexcept;

}
