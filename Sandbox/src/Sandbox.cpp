#include <Progenitor.h>

class Sandbox : public Gen::Application
{
public:
	Sandbox(){}
	~Sandbox(){}
};

Gen::Application* Gen::CreateApplication()
{
	return new Sandbox();
}