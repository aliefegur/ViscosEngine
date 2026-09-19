#include "KeyCode.h"

namespace Viscos {

	std::string KeyCodeToString(KeyCode keyCode) noexcept
	{
		switch (keyCode)
		{
		case KeyCode::Unknown: return "Unknown";
		case KeyCode::Space: return "Space";
		case KeyCode::Apostrophe: return "Apostrophe";
		case KeyCode::Comma: return "Comma";
		case KeyCode::Minus: return "Minus";
		case KeyCode::Period: return "Period";
		case KeyCode::Slash: return "Slash";
		case KeyCode::D0: return "D0";
		case KeyCode::D1: return "D1";
		case KeyCode::D2: return "D2";
		case KeyCode::D3: return "D3";
		case KeyCode::D4: return "D4";
		case KeyCode::D5: return "D5";
		case KeyCode::D6: return "D6";
		case KeyCode::D7: return "D7";
		case KeyCode::D8: return "D8";
		case KeyCode::D9: return "D9";
		case KeyCode::Semicolon: return "Semicolon";
		case KeyCode::Equal: return "Equal";
		case KeyCode::A: return "A";
		case KeyCode::B: return "B";
		case KeyCode::C: return "C";
		case KeyCode::D: return "D";
		case KeyCode::E: return "E";
		case KeyCode::F: return "F";
		case KeyCode::G: return "G";
		case KeyCode::H: return "H";
		case KeyCode::I: return "I";
		case KeyCode::J: return "J";
		case KeyCode::K: return "K";
		case KeyCode::L: return "L";
		case KeyCode::M: return "M";
		case KeyCode::N: return "N";
		case KeyCode::O: return "O";
		case KeyCode::P: return "P";
		case KeyCode::Q: return "Q";
		case KeyCode::R: return "R";
		case KeyCode::S: return "S";
		case KeyCode::T: return "T";
		case KeyCode::U: return "U";
		case KeyCode::V: return "V";
		case KeyCode::W: return "W";
		case KeyCode::X: return "X";
		case KeyCode::Y: return "Y";
		case KeyCode::Z: return "Z";
		case KeyCode::LeftBracket: return "Left Bracket";
		case KeyCode::Backslash: return "Backslash";
		case KeyCode::RightBracket: return "Right Bracket";
		case KeyCode::GraveAccent: return "Grave Accent";
		case KeyCode::Escape: return "Escape";
		case KeyCode::Enter: return "Enter";
		case KeyCode::Tab: return "Tab";
		case KeyCode::Backspace: return "Backspace";
		case KeyCode::Insert: return "Insert";
		case KeyCode::Delete: return "Delete";
		case KeyCode::Right: return "Right";
		case KeyCode::Left: return "Left";
		case KeyCode::Down: return "Down";
		case KeyCode::Up: return "Up";
		case KeyCode::PageUp: return "Page Up";
		case KeyCode::PageDown: return "Page Down";
		case KeyCode::Home: return "Home";
		case KeyCode::End: return "End";
		case KeyCode::CapsLock: return "Caps Lock";
		case KeyCode::ScrollLock: return "Scroll Lock";
		case KeyCode::NumLock: return "Num Lock";
		case KeyCode::PrintScreen: return "Print Screen";
		case KeyCode::Pause: return "Pause";
		case KeyCode::F1: return "F1";
		case KeyCode::F2: return "F2";
		case KeyCode::F3: return "F3";
		case KeyCode::F4: return "F4";
		case KeyCode::F5: return "F5";
		case KeyCode::F6: return "F6";
		case KeyCode::F7: return "F7";
		case KeyCode::F8: return "F8";
		case KeyCode::F9: return "F9";
		case KeyCode::F10: return "F10";
		case KeyCode::F11: return "F11";
		case KeyCode::F12: return "F12";
		case KeyCode::LeftShift: return "Left Shift";
		case KeyCode::LeftControl: return "Left Control";
		case KeyCode::LeftAlt: return "Left Alt";
		case KeyCode::LeftSuper: return "Left Super";
		case KeyCode::RightShift: return "Right Shift";
		case KeyCode::RightControl: return "Right Control";
		case KeyCode::RightAlt: return "Right Alt";
		case KeyCode::RightSuper: return "Right Super";
		case KeyCode::Menu: return "Menu";
		case KeyCode::Count: return "Count";
		case KeyCode::Num0: return "Num 0";
		case KeyCode::Num1: return "Num 1";
		case KeyCode::Num2: return "Num 2";
		case KeyCode::Num3: return "Num 3";
		case KeyCode::Num4: return "Num 4";
		case KeyCode::Num5: return "Num 5";
		case KeyCode::Num6: return "Num 6";
		case KeyCode::Num7: return "Num 7";
		case KeyCode::Num8: return "Num 8";
		case KeyCode::Num9: return "Num 9";
		case KeyCode::NumDecimal: return "Num Decimal";
		case KeyCode::NumDivide: return "Num Divide";
		case KeyCode::NumMultiply: return "Num Multiply";
		case KeyCode::NumSubtract: return "Num Subtract";
		case KeyCode::NumAdd: return "Numm Add";
		case KeyCode::NumEnter: return "Num Enter";
		case KeyCode::OEM8: return "OEM8";
		case KeyCode::OEM102: return "OEM102";
		default: return "Unknown";
		}
	}

}
