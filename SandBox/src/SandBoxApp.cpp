
#include <Render3D.h>

class ExampleLayer : public Render3D::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{ }

	void OnUpdate() override
	{
		bool status = Render3D::Input::IsKeyPress(R3D_KEY_TAB);
		if (status)
		{
			R3D_TRACE("The Tab IS Pressed");
		}
	}

	void OnEvent(Render3D::Event& event) override
	{
		if (event.GetEventType() == Render3D::EventType::KeyPressed)
		{
			Render3D::KeyPressedEvent& e = (Render3D::KeyPressedEvent&)event;
			R3D_TRACE("The Pressed Key : {0}", (char)e.GetKeyCode());
		}
	}

};

class SandBox : public Render3D::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer);
		PushOverlay(new Render3D::ImGuiLayer());
	}
	~SandBox()
	{

	}



private:

};

Render3D::Application* Render3D::CreateApplication()
{
	return new SandBox();
}

