#pragma once
#include "Core.h"

namespace Gen
{
	class GEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}

