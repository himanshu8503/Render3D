#pragma once

#include "R3Dpch.h"
#include "Core.h"
#include "Window.h"

#include "Events/ApplicationEvent.h"

namespace Render3D
{
	class R3D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_running = true;
	};

	Application* CreateApplication();

}



