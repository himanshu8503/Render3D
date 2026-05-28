#pragma once

#ifdef R3D_PLATFORM_WINDOWS

extern Render3D::Application* Render3D::CreateApplication();

int main(int argc, char** argv)
{
	Render3D::Log::Init();
	R3D_CORE_TRACE("The Engine is Running!");
	R3D_TRACE("App is working YAA");


	auto app = Render3D::CreateApplication();
	app->Run();
	delete app;

}

#endif 

