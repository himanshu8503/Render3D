#pragma once

#ifdef R3D_PLATFORM_WINDOWS
	#ifdef R3D_DLL_BUILD 
		#define R3D_API __declspec(dllexport)
	#else 
		#define R3D_API __declspec(dllimport)
	#endif 
#else
	#error Render3D only Support the Windows!
#endif 

#define BIT(x) (1 << x)

#ifdef R3D_DEBUG
	#define	R3D_ENABLE_ASSERS
#endif 

#ifdef R3D_ENABLE_ASSERS
	#define R3D_ASSERT(x,...) { if(!(x)) { R3D_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak(); }}
	#define R3D_CORE_ASSERT(x,...) { if(!(x)) { R3D_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak(); }}
#else
	#define R3D_ASSERT(x,...)
	#define R3D_CORE_ASSERT(x,...)
#endif 

