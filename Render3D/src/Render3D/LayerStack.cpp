#include "R3Dpch.h"
#include "LayerStack.h"

Render3D::LayerStack::LayerStack()
{
	m_LayerInsert = m_Layers.begin();
}

Render3D::LayerStack::~LayerStack()
{
	for (Layer* layer : m_Layers)
	{
		delete layer;
	}
}

void Render3D::LayerStack::PushLayer(Layer* layer)
{
	m_Layers.emplace(m_LayerInsert, layer);
}

void Render3D::LayerStack::PushOverlay(Layer* overlay)
{
	m_Layers.emplace_back(overlay);
}

void Render3D::LayerStack::PopLayer(Layer* layer)
{
	std::vector<Layer*>::iterator it = std::find(m_Layers.begin(), m_Layers.end(), layer);
	if (it != m_Layers.end())
	{
		m_Layers.erase(it);
		m_LayerInsert--;
	}
}

void Render3D::LayerStack::PopOverlay(Layer* overlay)
{
	std::vector<Layer*>::iterator it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
	if (it != m_Layers.end())
	{
		m_Layers.erase(it);
	}

}
