#include "IC.h"

IC::IC()
{
}

IC::~IC()
{
}

void IC::Update()
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

void IC::AddListener(InputListener* listener)
{
	m_listeners.insert(std::make_pair<InputListener*, InputListener*>(std::forward< InputListener*>(listener), std::forward< InputListener*>(listener)));
}

void IC::RemoveListener(InputListener* listener)
{
	std::map<InputListener*, InputListener*>::iterator it = m_listeners.find(listener);

	if (it != m_listeners.end())
	{
		m_listeners.erase(it);
	}
}

IC* IC::Get()
{
	static IC ic;
	return &ic;
}
