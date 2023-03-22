#pragma once
#include "Input.h"
#include "InputListener.h"
#include <map>
#include <string>

class InputController
{
public:
	InputController();
	~InputController();

	static InputController* Get();

	void Update();

	void BindControl(std::string action, int key);
	void UnbindControl(std::string action);

	void AddListener(InputListener* listener);
	void RemoveListener(InputListener* listener);

	std::map<std::string, int> m_controls;
	std::map<InputListener*, InputListener*> m_listeners;
	unsigned char m_keysState[256] = {};
	unsigned char m_oldKeysState[256] = {};

protected:
	//Methods
	void InitControls();

};
