#pragma once

#include "Event.h"

namespace Viscos {

	class WindowCloseEvent : public Event 
	{
	public:
		WindowCloseEvent() = default;

		std::string ToString() const noexcept override { return "WindowCloseEvent"; }

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryWindow);
	};

	class WindowResizeEvent : public Event 
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:
			m_Width(width), m_Height(height) { }

		unsigned int GetWidth() const noexcept { return m_Width; }
		unsigned int GetHeight() const noexcept { return m_Height; }

		std::string ToString() const noexcept override 
		{
			return "WindowResizeEvent: " + std::to_string(m_Width) + ", " + std::to_string(m_Height);
		}

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryWindow);

	private:
		unsigned int	m_Width,
						m_Height;
	};

	class WindowFocusEvent : public Event 
	{
	public:
		WindowFocusEvent() = default;

		std::string ToString() const noexcept override { return "WindowFocusEvent"; }

		EVENT_CLASS_TYPE(WindowFocus);
		EVENT_CLASS_CATEGORY(EventCategoryWindow);
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() = default;

		std::string ToString() const noexcept override { return "WindowLostFocusEvent"; }

		EVENT_CLASS_TYPE(WindowLostFocus);
		EVENT_CLASS_CATEGORY(EventCategoryWindow);
	};

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int x, int y) : m_X(x), m_Y(y) { }

		int GetX() const noexcept { return m_X; }
		int GetY() const noexcept { return m_Y; }

		std::string ToString() const noexcept override 
		{
			return "WindowMovedEvent: " + std::to_string(m_X), ", " + std::to_string(m_Y);
		}

		EVENT_CLASS_TYPE(WindowMoved);
		EVENT_CLASS_CATEGORY(EventCategoryWindow);

	private:
		int m_X, m_Y;
	};

}
