#include "KeyCode.h"

namespace Viscos {

	std::string KeyCodeToString(KeyCode keyCode) noexcept
	{
		switch (keyCode)
		{
		case Viscos::KeyCode::Unknown: return "Unknown";
		case Viscos::KeyCode::Space: return "Space";
		case Viscos::KeyCode::Apostrophe: return "Apostrophe";
		case Viscos::KeyCode::Comma: return "Comma";
		case Viscos::KeyCode::Minus: return "Minus";
		case Viscos::KeyCode::Period: return "Period";
		case Viscos::KeyCode::Slash: return "Slash";
		case Viscos::KeyCode::D0: return "D0";
		case Viscos::KeyCode::D1: return "D1";
		case Viscos::KeyCode::D2: return "D2";
		case Viscos::KeyCode::D3: return "D3";
		case Viscos::KeyCode::D4: return "D4";
		case Viscos::KeyCode::D5: return "D5";
		case Viscos::KeyCode::D6: return "D6";
		case Viscos::KeyCode::D7: return "D7";
		case Viscos::KeyCode::D8: return "D8";
		case Viscos::KeyCode::D9: return "D9";
		case Viscos::KeyCode::Semicolon: return "Semicolon";
		case Viscos::KeyCode::Equal: return "Equal";
		case Viscos::KeyCode::A: return "A";
		case Viscos::KeyCode::B: return "B";
		case Viscos::KeyCode::C: return "C";
		case Viscos::KeyCode::D: return "D";
		case Viscos::KeyCode::E: return "E";
		case Viscos::KeyCode::F: return "F";
		case Viscos::KeyCode::G: return "G";
		case Viscos::KeyCode::H: return "H";
		case Viscos::KeyCode::I: return "I";
		case Viscos::KeyCode::J: return "J";
		case Viscos::KeyCode::K: return "K";
		case Viscos::KeyCode::L: return "L";
		case Viscos::KeyCode::M: return "M";
		case Viscos::KeyCode::N: return "N";
		case Viscos::KeyCode::O: return "O";
		case Viscos::KeyCode::P: return "P";
		case Viscos::KeyCode::Q: return "Q";
		case Viscos::KeyCode::R: return "R";
		case Viscos::KeyCode::S: return "S";
		case Viscos::KeyCode::T: return "T";
		case Viscos::KeyCode::U: return "U";
		case Viscos::KeyCode::V: return "V";
		case Viscos::KeyCode::W: return "W";
		case Viscos::KeyCode::X: return "X";
		case Viscos::KeyCode::Y: return "Y";
		case Viscos::KeyCode::Z: return "Z";
		case Viscos::KeyCode::LeftBracket: return "LeftBracket";
		case Viscos::KeyCode::Backslash: return "Backslash";
		case Viscos::KeyCode::RightBracket: return "RightBracket";
		case Viscos::KeyCode::GraveAccent: return "GraveAccent";
		case Viscos::KeyCode::Escape: return "Escape";
		case Viscos::KeyCode::Enter: return "Enter";
		case Viscos::KeyCode::Tab: return "Tab";
		case Viscos::KeyCode::Backspace: return "Backspace";
		case Viscos::KeyCode::Insert: return "Insert";
		case Viscos::KeyCode::Delete: return "Delete";
		case Viscos::KeyCode::Right: return "Right";
		case Viscos::KeyCode::Left: return "Left";
		case Viscos::KeyCode::Down: return "Down";
		case Viscos::KeyCode::Up: return "Up";
		case Viscos::KeyCode::PageUp: return "PageUp";
		case Viscos::KeyCode::PageDown: return "PageDown";
		case Viscos::KeyCode::Home: return "Home";
		case Viscos::KeyCode::End: return "End";
		case Viscos::KeyCode::CapsLock: return "CapsLock";
		case Viscos::KeyCode::ScrollLock: return "ScrollLock";
		case Viscos::KeyCode::NumLock: return "NumLock";
		case Viscos::KeyCode::PrintScreen: return "PrintScreen";
		case Viscos::KeyCode::Pause: return "Pause";
		case Viscos::KeyCode::F1: return "F1";
		case Viscos::KeyCode::F2: return "F2";
		case Viscos::KeyCode::F3: return "F3";
		case Viscos::KeyCode::F4: return "F4";
		case Viscos::KeyCode::F5: return "F5";
		case Viscos::KeyCode::F6: return "F6";
		case Viscos::KeyCode::F7: return "F7";
		case Viscos::KeyCode::F8: return "F8";
		case Viscos::KeyCode::F9: return "F9";
		case Viscos::KeyCode::F10: return "F10";
		case Viscos::KeyCode::F11: return "F11";
		case Viscos::KeyCode::F12: return "F12";
		case Viscos::KeyCode::LeftShift: return "LeftShift";
		case Viscos::KeyCode::LeftControl: return "LeftControl";
		case Viscos::KeyCode::LeftAlt: return "LeftAlt";
		case Viscos::KeyCode::LeftSuper: return "LeftSuper";
		case Viscos::KeyCode::RightShift: return "RightShift";
		case Viscos::KeyCode::RightControl: return "RightControl";
		case Viscos::KeyCode::RightAlt: return "RightAlt";
		case Viscos::KeyCode::RightSuper: return "RightSuper";
		case Viscos::KeyCode::Menu: return "Menu";
		case Viscos::KeyCode::Count: return "Count";
		default: return "Unknown";
		}
	}

}
