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