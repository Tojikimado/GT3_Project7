#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Image
{
protected:
    IDirect3DDevice9* m_device;
    IDirect3DTexture9* m_texture;
    LPD3DXSPRITE m_sprite;
    D3DXVECTOR2 m_position;
    D3DXVECTOR2 m_size;
    D3DXVECTOR2 m_convertSize;
    D3DXMATRIX m_matrix;
    D3DCOLOR m_color;


public:

    Image(IDirect3DDevice9* device, LPCWSTR imagePath, D3DXVECTOR2 position, D3DXVECTOR2 size, D3DCOLOR color);
    ~Image();

    void Draw();
    void SetSize(D3DXVECTOR2 size, int clientWidth, int clienHeight, int renderWidth, int renderHeight);
    bool LoadTexture(LPCWSTR imagePath);
};