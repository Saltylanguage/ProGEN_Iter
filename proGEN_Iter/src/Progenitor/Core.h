#pragma once

#ifdef  GEN_PLATFORM_WINDOWS
	#ifdef GEN_BUILD_DLL
		#define GEN_API __declspec(dllexport)
	#else
		#define GEN_API __declspec(dllimport)
	#endif // GEN_BUILD_DLL
#else 
	#error Hazel only supports Windows!
#endif //  GEN_PLATFORM_WINDOWS