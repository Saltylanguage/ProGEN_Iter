#include <Progenitor.h>



class ExampleLayer : public Gen::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		//SQUAK_INFO("ExampleLayer::Update");
	}

	void OnAttach() {}
	void OnDetach() {}

	void OnEvent(Gen::Event& event) override
	{
		//SQUAK_INFO("{0}", event);
	}

};

class Sandbox : public Gen::Application
{
public:
	Sandbox():Application()
	{
		//PushLayer(new ExampleLayer());
		PushOverlay(new Gen::ImGuiLayer());
		Application::Get().GetWindow().SetEventCallback((BIND_EVENT_FN(Sandbox::OnEvent)));
		
	}
	void OnEvent(Gen::Event& e)
	{
		//SQUAK_INFO("{0}", e);
		Application::OnEvent(e);
	}
	~Sandbox(){}
};

Gen::Application* Gen::CreateApplication()
{
	return new Sandbox();
}