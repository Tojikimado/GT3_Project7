#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include "d3dUtil.h"

class Label
{
protected:
	std::string m_caption;
	LPD3DXFONT m_font;
	D3DXCOLOR m_color;
	DWORD m_format;
	RECT m_rect;

public:
	Label(IDirect3DDevice9* device);
	~Label();

	bool OnRender();
	void SetCaption(std::string caption);
	std::string GetCaption();
	void SetColor(D3DXCOLOR color);
	D3DXCOLOR GetColor();
	void SetFormat(DWORD format);
	DWORD GetFormat();
	void SetRect(int left, int top, int right, int bottom);
	RECT GetRect();

};
