#include "InputControlle.h"

InputController::InputController()
{
	InitControls();
}

void InputController::InitControls()
{
	m_controls.insert({ "Menu", Input::DXK_ESCAPE });
}

void InputController::BindControl(std::string action, int key)
{
	if(m_controls.find(action) != m_controls.end())
		m_controls.at(action) = key;
}

void InputController::UnbindControl(std::string action)
{
	if (m_controls.find(action) != m_controls.end())
		m_controls.at(action) = NULL;
}

