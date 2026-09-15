#pragma once

#include "Event.h"

namespace Viscos {

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) { }

		float GetX() const noexcept { return m_MouseX; }
		float GetY() const noexcept { return m_MouseY; }

		std::string ToString() const noexcept override
		{
			return "MouseMovedEvent: " + std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY);
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) { }

		float GetXOffset() const noexcept { return m_XOffset; }
		float GetYOffset() const noexcept { return m_YOffset; }

		std::string ToString() const noexcept override
		{
			return "MouseScrolledEvent: " + std::to_string(m_XOffset) + ", " + std::to_string(m_YOffset);
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	private:
		float m_XOffset, m_YOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		int GetMouseButton() const noexcept { return m_Button; }
		
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton);

	protected:
		MouseButtonEvent(int button) : m_Button(button) { }

		int m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) { }

		std::string ToString() const noexcept override
		{
			return "MouseButtonPressedEvent: " + std::to_string(m_Button);
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const noexcept override
		{
			return "MouseButtonReleasedEvent: " + std::to_string(m_Button);
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};

}
