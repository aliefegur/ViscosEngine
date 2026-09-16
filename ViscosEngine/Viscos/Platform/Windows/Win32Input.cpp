#include "Win32Input.h"

namespace Viscos {

	bool Win32Input::IsKeyPressed(KeyCode key) const 
	{
		const auto index = static_cast<size_t>(key);

		if (index >= KeyCodeCount)
			return false;

		return m_KeyStates[index];
	}

	void Win32Input::SetKeyState(KeyCode key, bool pressed)
	{
		const auto index = static_cast<size_t>(key);

		if (index >= KeyCodeCount)
			return;

		m_KeyStates[index] = pressed;
	}

	KeyCode Win32Input::TranslateKeyCode(uint32_t virtualKey)
	{
        switch (virtualKey)
        {
        case VK_SPACE:    return KeyCode::Space;
        case VK_ESCAPE:   return KeyCode::Escape;
        case VK_RETURN:   return KeyCode::Enter;
        case VK_TAB:      return KeyCode::Tab;
        case VK_BACK:     return KeyCode::Backspace;
        case VK_INSERT:   return KeyCode::Insert;
        case VK_DELETE:   return KeyCode::Delete;

        case VK_RIGHT:    return KeyCode::Right;
        case VK_LEFT:     return KeyCode::Left;
        case VK_DOWN:     return KeyCode::Down;
        case VK_UP:       return KeyCode::Up;

        case VK_PRIOR:    return KeyCode::PageUp;
        case VK_NEXT:     return KeyCode::PageDown;
        case VK_HOME:     return KeyCode::Home;
        case VK_END:      return KeyCode::End;

        case VK_CAPITAL:  return KeyCode::CapsLock;
        case VK_SCROLL:   return KeyCode::ScrollLock;
        case VK_NUMLOCK:  return KeyCode::NumLock;

        case VK_SNAPSHOT: return KeyCode::PrintScreen;
        case VK_PAUSE:    return KeyCode::Pause;

        case VK_F1:       return KeyCode::F1;
        case VK_F2:       return KeyCode::F2;
        case VK_F3:       return KeyCode::F3;
        case VK_F4:       return KeyCode::F4;
        case VK_F5:       return KeyCode::F5;
        case VK_F6:       return KeyCode::F6;
        case VK_F7:       return KeyCode::F7;
        case VK_F8:       return KeyCode::F8;
        case VK_F9:       return KeyCode::F9;
        case VK_F10:      return KeyCode::F10;
        case VK_F11:      return KeyCode::F11;
        case VK_F12:      return KeyCode::F12;

        case VK_LSHIFT:   return KeyCode::LeftShift;
        case VK_RSHIFT:   return KeyCode::RightShift;
        case VK_LCONTROL: return KeyCode::LeftControl;
        case VK_RCONTROL: return KeyCode::RightControl;
        case VK_LMENU:    return KeyCode::LeftAlt;
        case VK_RMENU:    return KeyCode::RightAlt;
        case VK_LWIN:     return KeyCode::LeftSuper;
        case VK_RWIN:     return KeyCode::RightSuper;

        case VK_APPS:     return KeyCode::Menu;

        default:
            break;
        }

        // Alphabetic keys
        if (virtualKey >= 'A' && virtualKey <= 'Z')
        {
            return static_cast<KeyCode>(
                static_cast<uint16_t>(KeyCode::A) +
                (virtualKey - 'A')
                );
        }

        // Numeric keys
        if (virtualKey >= '0' && virtualKey <= '9')
        {
            return static_cast<KeyCode>(
                static_cast<uint16_t>(KeyCode::D0) + (virtualKey - '0')
            );
        }

        return KeyCode::Unknown;
	}

}
