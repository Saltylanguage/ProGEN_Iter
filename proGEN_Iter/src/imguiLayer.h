#pragma once
#include "Layer.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"

namespace Gen
{
	class GEN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;


	private:
		bool OnMouseButtonPressedEvent(MouseButtonEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonEvent& e);
		bool OnMouseMovedEvent(MouseMoveEvent& e);
		bool OnMouseScrolledEvent(MouseScrollEvent& e);
		
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleaseEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		
		bool OnWindowResizedEvent(WindowResizeEvent& e);
		bool OnWindowClosedEvent(KeyTypedEvent& e);


	private:
		float m_Time = 0.0f;
	};
}