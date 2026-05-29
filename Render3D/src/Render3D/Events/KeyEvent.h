#pragma once

#include "Render3D/Events/Event.h"


namespace Render3D {

	class KeyEvent :public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput )
	protected:
		KeyEvent(int KeyCode)
			:m_KeyCode(KeyCode)
		{ }

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int KeyCode,int RepeatCount)
			: KeyEvent(KeyCode), m_RepeatCount(RepeatCount)
		{ }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " ( " << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int KeyCode)
			:KeyEvent(KeyCode)
		{ }


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	private:

	};

	class KeyTypedEvent : public KeyEvent
	{
	public: 
		KeyTypedEvent(int KeyCode)
			: KeyEvent(KeyCode)
		{ }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}
