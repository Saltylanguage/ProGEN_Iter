#include "Application.h"

class Sandbox : public Gen::Application
{
public:
	Sandbox():Application()
	{
		Application::Get().GetWindow().SetEventCallback((BIND_EVENT_FN(Sandbox::OnEvent)));
	}

	void OnEvent(Gen::Event& e)
	{
		Application::OnEvent(e);
	}
	~Sandbox(){}
};

Gen::Application* Gen::CreateApplication()
{
	return new Sandbox();
}

