#pragma once

#include "Event.h"
#include "Viscos/Input/KeyCode.h"

namespace Viscos {

	class KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const noexcept { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);

	protected:
		KeyEvent(KeyCode keyCode) : m_KeyCode(keyCode) { }

		KeyCode m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keyCode, bool isRepeat) : KeyEvent(keyCode), m_IsRepeat(isRepeat) { }

		bool IsRepeat() const noexcept { return m_IsRepeat; }

		std::string ToString() const noexcept override
		{
			return "KeyPressedEvent: " + KeyCodeToString(m_KeyCode) + ", repeat=" + std::to_string(m_IsRepeat);
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		bool m_IsRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode keyCode) : KeyEvent(keyCode) { }

		std::string ToString() const noexcept override
		{
			return "KeyReleasedEvent: " + KeyCodeToString(m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

}
