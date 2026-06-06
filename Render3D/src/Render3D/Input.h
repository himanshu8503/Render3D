#pragma once

#include "Render3D/Core.h"

namespace Render3D
{
	class R3D_API Input
	{
	public:
		inline static bool IsKeyPress(int Keycode) { return s_Instance->IsKeyPressImpl(Keycode); }
		inline static bool IsMouseButtonPress(int Button) { return s_Instance->IsMouseButtonPressImpl(Button); }

		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected:
		virtual bool IsKeyPressImpl(int Keycode) = 0;
		virtual bool IsMouseButtonPressImpl(int Button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Input* s_Instance;
	};
}
