#pragma once
#include "Event.h"

#include <sstream>

namespace Gen
{
	class GEN_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y): m_MouseX(x), m_MouseY(y) {}

		inline float GetX() { return m_MouseX; }
		inline float GetY() { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse| EventCategoryInput)
	private:
		float m_MouseX;
		float m_MouseY;
	};

	class GEN_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset;
		float m_YOffset;
	};

	class GEN_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		
		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};

	class GEN_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button; 
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class GEN_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonRelasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
