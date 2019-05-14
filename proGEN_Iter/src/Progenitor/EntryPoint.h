#pragma once

extern Gen::Application* Gen::CreateApplication();

#ifdef GEN_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	printf("Progenitor Engine Starting Up...\n");
	auto app = Gen::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif // GEN_PLATFORM_WINDOWS
