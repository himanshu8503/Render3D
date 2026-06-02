#include "R3Dpch.h"
#include "Application.h"

#include "Render3D/Events/ApplicationEvent.h"
#include "Render3D/Events/Event.h"

#include <glad/glad.h>


namespace Render3D
{
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)
	
	Application* Application::s_Instance = nullptr;

	Render3D::Application::Application()
	{
		R3D_CORE_ASSERT(!s_Instance, "Application is already exist!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	}

	Render3D::Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}


	void Render3D::Application::Run()
	{


		while (m_running)
		{
			
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();

			glClear(GL_COLOR_BUFFER_BIT);
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_running = false;
		return true;
	}

}


