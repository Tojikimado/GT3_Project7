#pragma once
#include "Input.h"
#include <map>
#include <string>

class InputController
{
public:
	InputController();

	std::map<std::string, int> m_controls;

protected:
	//Methods
	void InitControls();
	void BindControl(std::string action, int key);
	void UnbindControl(std::string action);

};
