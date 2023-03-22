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
    if (::GetKeyboardState(m_keysState))
    {
        for (unsigned int i = 0; i < 256; i++)
        {
            //Key Down
            if (m_keysState[i] & 0x80)
            {
                std::map<InputListener*, InputListener*>::iterator it = m_listeners.begin();

                while (it != m_listeners.end())
                {
                    it->second->OnKeyDown(i);
                    ++it;
                }
            }
            //Key Up
            else
            {
                if (m_keysState[i] != m_oldKeysState[i])
                {
                    std::map<InputListener*, InputListener*>::iterator it = m_listeners.begin();

                    while (it != m_listeners.end())
                    {
                        it->second->OnKeyUp(i);
                        ++it;
                    }
                }
            }
        }
        //Stocke l'état actuel de la clé dans le buffer de l'ancienne clé
        ::memcpy(m_oldKeysState, m_keysState, sizeof(unsigned char) * 256);
    }
}

void InputController::InitControls()
{
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

void InputController::AddListener(InputListener* listener)
{
    m_listeners.insert(std::make_pair<InputListener*, InputListener*>(std::forward< InputListener*>(listener), std::forward< InputListener*>(listener)));
}

void InputController::RemoveListener(InputListener* listener)
{
    std::map<InputListener*, InputListener*>::iterator it = m_listeners.find(listener);

    if (it != m_listeners.end())
    {
        m_listeners.erase(it);
    }
}

