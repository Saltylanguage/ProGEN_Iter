#include "Application.h"

class Sandbox : public Gen::Application
{
public:
	Sandbox():Application()
	{
		PushOverlay(new Gen::ImGuiLayer());
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

int main(int argc, char** argv)
{
	Gen::Squak::Init();

	printf("Engine Features Loading...\n");

	auto app = Gen::CreateApplication();
	// ========================================================================
	//			WRITE YOUR GAME LOOP INSIDE THE app->Run() FUNCTION
	// ========================================================================
	app->Run();
	delete app;
	return 0;
}