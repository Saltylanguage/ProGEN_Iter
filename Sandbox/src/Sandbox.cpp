#include <Progenitor.h>

class Sandbox : public Gen::Application
{
public:
	Sandbox():Application(){}
	~Sandbox(){}
};

Gen::Application* Gen::CreateApplication()
{
	return new Sandbox();
}