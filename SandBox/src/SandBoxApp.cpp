
#include <Render3D.h>

class SandBox : public Render3D::Application
{
public:
	SandBox()
	{

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

