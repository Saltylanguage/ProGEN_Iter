#pragma once


extern Gen::Application* Gen::CreateApplication();

#ifdef GEN_PLATFORM_WINDOWS
int main(int argc, char** argv)
{ 
	Gen::Squak::Init();
	SQUAK_CORE_INFO("Core Info");
	SQUAK_CORE_WARNING("Core Warning");
	SQUAK_CORE_ERROR("Core Error");
	

	SQUAK_INFO("Squak Info");
	SQUAK_WARNING("Squak Warning");
	SQUAK_ERROR("Squak Error");
	printf("Engine Features Loading...\n");

	auto app = Gen::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif // GEN_PLATFORM_WINDOWS
