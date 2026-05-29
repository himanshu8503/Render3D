#include "Application.h"

#include "Render3D/Log.h"
#include "Render3D/Events/ApplicationEvent.h"
#include "Render3D/Events/Event.h"


namespace Render3D
{
	Render3D::Application::Application()
	{
	}

	Render3D::Application::~Application()
	{
	}

	void Render3D::Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		R3D_TRACE("{0}", e);

		while (true);

	}
}


