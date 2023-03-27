#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Label
{
protected:
	char m_caption[255];
	LPD3DXFONT m_font;
	D3DXCOLOR m_color;
	DWORD m_format;

public:
	Label(LOGFONT font, LPDIRECT3DDEVICE9 device);
	~Label();

	bool OnRender();
	void SetCaption(char* caption);
	char* GetCaption();
	void SetColor(D3DXCOLOR color);
	D3DXCOLOR GetColor();
	void SetFormat(DWORD format);
	DWORD GetFormat();
};
