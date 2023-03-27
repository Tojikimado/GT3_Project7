#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Label.h"

class Button
{
protected:
	HFONT m_font;
	Label* m_caption;
	bool m_pressed;
	D3DXCOLOR m_defaultColor;
	D3DXCOLOR m_pressedColor;

public:
	Button(IDirect3DDevice9* device);
	~Button();

	bool OnRender();
	void OnSetFocus();
	void OnLostFocus();
	void SetCaption(IDirect3DDevice9* device, std::string Caption);
	bool SetUnpressedImage(char* File);
	bool SetPressedImage(char* File);
};