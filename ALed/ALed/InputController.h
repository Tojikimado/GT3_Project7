#pragma once
#include "Input.h"
#include <map>
#include <string>

class InputController
{
public:
	enum
	{
		NONE,
		DOWN,
		HOLD,
		UP,
	};

public:
	InputController();
	~InputController();

	static InputController* Get();

	void Update();

	void BindControl(std::string action, int key);
	void UnbindControl(std::string action);

	bool IsKey(int key) { return m_keys[key] == DOWN || m_keys[VK_LBUTTON] == HOLD; }
	bool IsKeyDown(int key) { return m_keys[key] == DOWN; }
	bool IsKeyUp(int key) { return m_keys[key] == UP; }

	int GetMouseX(HWND hWnd);
	int GetMouseY(HWND hWnd);

	std::map<std::string, int> m_controls;
	BYTE m_keys[256];
	POINT m_pt;

protected:
	//Methods
	void InitControls();

};
