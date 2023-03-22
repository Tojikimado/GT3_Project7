#pragma once
#include "Input.h"
#include "InputListener.h"
#include <map>

class IC
{
public:
	IC();
	~IC();

	void Update();
	void AddListener(InputListener* listener);
	void RemoveListener(InputListener * listener);

public:
	static IC* Get();

private:
	std::map<InputListener*, InputListener*> m_listeners;
	unsigned char m_keysState[256] = {};
	unsigned char m_oldKeysState[256] = {};
};