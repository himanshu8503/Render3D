
#include <Render3D.h>

class ExampleLayer : public Render3D::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{ }

	void OnUpdate() override
	{
		R3D_INFO("ExampleLayer::Update");
	}

	void OnEvent(Render3D::Event& event) override
	{
		R3D_TRACE("{0}", event);
	}

};

class SandBox : public Render3D::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer);
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

