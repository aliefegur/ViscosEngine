#pragma once

#include "Event.h"

namespace Viscos {

	class KeyEvent : public Event
	{
	public:
		int GetKeyCode() const noexcept { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);

	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode) { }

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, bool isRepeat) : KeyEvent(keyCode), m_IsRepeat(isRepeat) { }

		bool IsRepeat() const noexcept { return m_IsRepeat; }

		std::string ToString() const noexcept override
		{
			return "KeyPressedEvent: " + std::to_string(m_KeyCode) + ", repeat=" + std::to_string(m_IsRepeat);
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		bool m_IsRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) { }

		std::string ToString() const noexcept override
		{
			return "KeyReleasedEvent: " + std::to_string(m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

}
