#pragma once
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>

class MeshRenderer
{
public:
	virtual void Init(IDirect3DDevice9* m_pDevice3D) = 0;
	virtual void Render(IDirect3DDevice9* m_pDevice3D) = 0;
};

