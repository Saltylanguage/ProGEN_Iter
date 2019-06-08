#include "GenPCH.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Squak.h"


namespace Gen
{
	Application::Application(){}
	Application::~Application(){}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 800);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SQUAK_INFO(e.ToString());
		}

		while (true);
	}
}
