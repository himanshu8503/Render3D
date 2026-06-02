#pragma once

#include "R3Dpch.h"
#include "Window.h"

#include "Render3D/Core.h"
#include "Render3D/Events/ApplicationEvent.h"
#include "Render3D/LayerStack.h"

namespace Render3D
{
	class R3D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};

	Application* CreateApplication();

}



