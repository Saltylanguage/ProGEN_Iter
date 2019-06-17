#pragma once

#ifdef  GEN_PLATFORM_WINDOWS
	#ifdef GEN_BUILD_DLL
		#define GEN_API 
	#else
		#define GEN_API 
	#endif // GEN_BUILD_DLL
#else 
	#error Hazel only supports Windows!
#endif //  GEN_PLATFORM_WINDOWS

#ifdef GEN_DEBUG
	#define GEN_ENABLE_ASSERTS
#endif // GEN_DEBUG

#ifdef GEN_ENABLE_ASSERTS
	#define GEN_ASSERT(x, ...) { if(!(x)) {SQUAK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GEN_CORE_ASSERT(x, ...) {if(!(x)) {SQUAK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else 
	#define GEN_ASSERT(x, ...)	
	#define GEN_CORE_ASSERT(x, ...)
#endif // GEN_ENABLE_ASSERTS


#define BIT(x) (1 << x)
#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
