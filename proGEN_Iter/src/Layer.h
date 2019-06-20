#pragma once
#include "GenPCH.h"

namespace Gen
{
	class Event;
	class MouseButtonEvent;
	class MouseMoveEvent;
	class MouseScrolledEvent;

	class KeyPressedEvent;
	class KeyReleasedEvent;
	class KeyTypedEvent;

	class WindowResizedEvent;
	class WindowCloseEvent;

	class GEN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") {};
		virtual ~Layer() {};

		virtual void OnAttach(){};
		virtual void OnDetach(){};
		virtual void OnUpdate(){};
		virtual void OnImGuiRender() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}