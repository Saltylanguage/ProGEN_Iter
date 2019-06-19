#pragma once
#include "Layer.h"

namespace Gen
{
	class GEN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;

	private:
		virtual bool OnMouseButtonPressedEvent(MouseButtonEvent& e) override;
		virtual bool OnMouseButtonReleasedEvent(MouseButtonEvent& e) override;
		virtual bool OnMouseMovedEvent(MouseMoveEvent& e) override;
		virtual bool OnMouseScrolledEvent(MouseScrolledEvent& e) override;
		
		virtual bool OnKeyPressedEvent(KeyPressedEvent& e) override;
		virtual bool OnKeyReleasedEvent(KeyReleasedEvent& e) override;
		virtual bool OnKeyTypedEvent(KeyTypedEvent& e) override;
		
		virtual bool OnWindowResizedEvent(WindowResizedEvent& e) override;
		virtual bool OnWindowClosedEvent(WindowCloseEvent& e) override;
		
	private:
		float m_Time = 0.0f;
	};
}