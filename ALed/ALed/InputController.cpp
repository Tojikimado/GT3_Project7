#include "InputController.h"

InputController::InputController()
{
	InitControls();
}

InputController::~InputController()
{

}

InputController* InputController::Get()
{
	static InputController controller;
	return &controller;
}

void InputController::Update()
{
    for (int i = 0; i < 256; i++)
    {
        if (GetAsyncKeyState(i) < 0)
        {
            switch (m_keys[i])
            {
            case NONE:
                m_keys[i] = DOWN;
                break;
            case DOWN:
            case UP:
                m_keys[i] = HOLD;
                break;
            }
        }
        else
        {
            switch (m_keys[i])
            {
            case HOLD:
                m_keys[i] = UP;
                break;
            case UP:
            case DOWN:
                m_keys[i] = NONE;
                break;
            }

        }
    }
}

void InputController::InitControls()
{
    memset(m_keys, 0, 256);

	m_controls.insert({ "Menu", Input::DXK_ESCAPE });
	m_controls.insert({ "Forward", Input::DXK_Z });
	m_controls.insert({ "Back", Input::DXK_S });
	m_controls.insert({ "Left", Input::DXK_Q });
	m_controls.insert({ "Right", Input::DXK_D });
}

void InputController::BindControl(std::string action, int key)
{
	if (m_controls.find(action) != m_controls.end())
	{
		UnbindControl(action);
		m_controls[action] = key;
	}
}

void InputController::UnbindControl(std::string action)
{
	if (m_controls.find(action) != m_controls.end())
		m_controls.at(action) = NULL;
}

int InputController::GetMouseX()
{
    GetCursorPos(&m_pt);
    return m_pt.x;
}

int InputController::GetMouseY()
{
    GetCursorPos(&m_pt);
    return m_pt.y;
}

