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
		bool OnMouseButtonPressedEvent(MouseButtonEvent& e) override;
		bool OnMouseButtonReleasedEvent(MouseButtonEvent& e) override;
		bool OnMouseMovedEvent(MouseMoveEvent& e) override;
		bool OnMouseScrolledEvent(MouseScrolledEvent& e) override;
		
		bool OnKeyPressedEvent(KeyPressedEvent& e) override;
		bool OnKeyReleasedEvent(KeyReleasedEvent& e) override;
		bool OnKeyTypedEvent(KeyTypedEvent& e) override;
		
		bool OnWindowResizedEvent(WindowResizedEvent& e) override;
		bool OnWindowClosedEvent(KeyTypedEvent& e) override;


	private:
		float m_Time = 0.0f;
	};
}