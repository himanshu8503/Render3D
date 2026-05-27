#pragma once

#ifdef R3D_PLATFORM_WINDOWS

extern Render3D::Application* Render3D::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Render3D::CreateApplication();
	app->Run();
	delete app;

}

#endif 

