#pragma once

#include "Render3D/Input.h"

namespace Render3D
{

	class WindowsInput : public Input
	{
		virtual bool IsKeyPressImpl(int Keycode) override;

		virtual bool IsMouseButtonPressImpl(int Button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};



}
