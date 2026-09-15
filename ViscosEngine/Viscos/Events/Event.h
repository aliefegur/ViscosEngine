#pragma once

#include "Viscos/Core/API.h"

#include <string>

namespace Viscos {

    enum class EventType
    {
        None = 0,

        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,

        AppTick,
        AppUpdate,
        AppRender,

        KeyPressed,
        KeyReleased,

        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = 1 << 0,
        EventCategoryInput = 1 << 1,
        EventCategoryKeyboard = 1 << 2,
        EventCategoryMouse = 1 << 3,
        EventCategoryMouseButton = 1 << 4,
        EventCategoryWindow = 1 << 5
    };

	class VISCOS_API Event 
	{
	public:
		virtual ~Event() = default;

        virtual EventType GetEventType() const noexcept = 0;
        virtual const char* GetName() const noexcept = 0;
        virtual int GetCategoryFlags() const noexcept = 0;
        
        virtual std::string ToString() const noexcept;
        
        bool IsInCategory(EventCategory category) const noexcept;

        bool Handled = false;
	};

    class EventDispatcher
    {
    public:
        EventDispatcher(Event& e) : m_Event(e) {}

        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled |= func(static_cast<T&>(m_Event));
                return true;
            }

            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

}

#define EVENT_CLASS_TYPE(type)                                      \
    static EventType GetStaticType() { return EventType::type; }    \
    virtual EventType GetEventType() const noexcept override        \
    {                                                               \
        return GetStaticType();                                     \
    }                                                               \
    virtual const char* GetName() const noexcept override           \
    {                                                               \
        return #type;                                               \
    }

#define EVENT_CLASS_CATEGORY(category)                              \
    virtual int GetCategoryFlags() const noexcept override          \
    {                                                               \
        return category;                                            \
    }
