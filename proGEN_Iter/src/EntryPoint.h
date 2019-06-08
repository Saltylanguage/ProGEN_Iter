#pragma once

extern Gen::Application* Gen::CreateApplication();

#ifdef GEN_PLATFORM_WINDOWS
int main(int argc, char** argv)
{ 
	Gen::Squak::Init();

	printf("Engine Features Loading...\n");

	auto app = Gen::CreateApplication();
	// ========================================================================
	//			WRITE YOUR GAME LOOP INSIE THE app->Run() FUNCTION
	// ========================================================================
	app->Run();
	delete app;
	return 0;
}
#endif // GEN_PLATFORM_WINDOWS
