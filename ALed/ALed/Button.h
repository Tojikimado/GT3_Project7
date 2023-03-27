#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Label.h"

class Button
{
protected:
	HFONT m_font;
	Label* m_caption;
	bool m_isPressed;

public:
	Button(LPDIRECT3DDEVICE9 device);
	~Button();

	bool OnRender();
	void OnSetFocus();
	void OnLostFocus();
	void SetCaption(char* Caption);
	bool SetUnpressedImage(char* File);
	bool SetPressedImage(char* File);
};