#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Gen
{

	class MouseButtonEvent;
	class MouseMoveEvent;
	class MouseScrolledEvent;

	class KeyPressedEvent;
	class KeyReleasedEvent;
	class KeyTypedEvent;

	class WindowResizedEvent;

	class GEN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent(Event& event) = 0;

	private:
		virtual bool OnMouseButtonPressedEvent(MouseButtonEvent& e) { return false; }
		virtual bool OnMouseButtonReleasedEvent(MouseButtonEvent& e) { return false; }
		virtual bool OnMouseMovedEvent(MouseMoveEvent& e) { return false; }
		virtual bool OnMouseScrolledEvent(MouseScrolledEvent& e) { return false; }

		virtual bool OnKeyPressedEvent(KeyPressedEvent& e) { return false; }
		virtual bool OnKeyReleasedEvent(KeyReleasedEvent& e) { return false; }
		virtual bool OnKeyTypedEvent(KeyTypedEvent& e) { return false; }

		virtual bool OnWindowResizedEvent(WindowResizedEvent& e) { return false; }
		virtual bool OnWindowClosedEvent(KeyTypedEvent& e) { return false; }

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}