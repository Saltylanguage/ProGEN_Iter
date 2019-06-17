#include "GenPCH.h"
#include "Application.h"
#include "Squak.h"
#include <Glad/glad.h>
#include "Platform/Windows/WindowsKeys.h"

namespace Gen
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		GEN_CORE_ASSERT(s_Instance == nullptr, "Appliication already exists");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application(){}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			bool isPressed = Input::IsKeyPressed(GEN_KEY_BACKSPACE);
			if (isPressed)
			{
				SQUAK_CORE_TRACE("Key was Pressed.... Polling works!");
				auto[x, y] = Input::GetMousePos();
				SQUAK_CORE_TRACE("{0}, {1}", x, y);
			}


			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
