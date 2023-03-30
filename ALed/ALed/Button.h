#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Label.h"

class D3DApp;
class Label;
class Image;

class Button
{
protected:
	IDirect3DDevice9* m_device;
	IDirect3DTexture9* m_texture;
	Label* m_label;
	Image* m_image;
	POINT m_mousePos;

public:
	Button(IDirect3DDevice9* device, D3DApp* app, std::string caption, D3DCOLOR color, DWORD format, RECT rect);
	~Button();

	void Update(HWND hwnd);

	Label* GetLabel();
	Image* GetImage();
};