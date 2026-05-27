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

