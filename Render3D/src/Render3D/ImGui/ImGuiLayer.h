#pragma once

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

#include "Render3D/Layer.h"
#include "Render3d/Core.h"

#include "Render3D/Events/Event.h"
#include "Render3D/Events/ApplicationEvent.h"
#include "Render3D/Events/KeyEvent.h"
#include "Render3D/Events/MouseEvent.h"

namespace Render3D
{
	class R3D_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:
		float m_time = 0.0f;
		bool m_blokingEvent = true;
	};
}

