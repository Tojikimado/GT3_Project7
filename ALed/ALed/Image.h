#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "D3DApp.h"

class D3DApp;

class Image
{
protected:
    IDirect3DDevice9* m_device;
    IDirect3DTexture9* m_texture;
    LPD3DXSPRITE m_sprite;
    D3DXVECTOR3 m_position;
    D3DXVECTOR2 m_size;
    D3DCOLOR m_color;


public:

    Image(IDirect3DDevice9* device, LPCWSTR imagePath, D3DXVECTOR3 position, D3DXVECTOR2 size, D3DCOLOR color, D3DApp* app);
    ~Image();

    void Draw();
    bool LoadTexture(LPCWSTR imagePath);
    void SetPosition(D3DXVECTOR3 position);
    D3DXVECTOR3 GetPosition();
    void SetSize(D3DXVECTOR2 size, D3DApp* app);
    D3DXVECTOR2 GetSize();
    void SetColor(D3DCOLOR color);
    D3DCOLOR GetColor();
    LPD3DXSPRITE GetSprite();

};