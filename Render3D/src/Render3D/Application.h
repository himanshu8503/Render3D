#pragma once

#include "Core.h"

namespace Render3D
{
	class R3D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}



