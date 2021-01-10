#pragma once

#ifdef CT_PLATFORM_WINDOWS
	#ifdef CT_BUILD_DLL
		#define CITRINE_API __declspec(dllexport)
	#else
		#define	CITRINE_API __declspec(dllimport)
	#endif
#else
	#error Citrine only supports Windows!
#endif


#ifdef CT_ENABLE_ASSERTS
	#define CT_ASSERT(x, ...) { if(!(x)) {CT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CT_CORE_ASSERT(x, ...) { if(!(x)) {CT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CT_ASSERT(x, ...)
	#define CT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)