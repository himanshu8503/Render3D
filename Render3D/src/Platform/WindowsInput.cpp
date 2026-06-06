#include "R3Dpch.h"
#include "WindowsInput.h"

#include "Render3D/Application.h"
#include <GLFW/glfw3.h>

namespace Render3D
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressImpl(int Keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetKey(window, Keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::IsMouseButtonPressImpl(int Button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, Button);

		return state == GLFW_PRESS;
	}
	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}
	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePosition();
		return x;
	}
	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePosition();
		return y;
	}
}