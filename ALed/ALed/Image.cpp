#include "Image.h"
#include <string>
#include <iostream>

Image::Image(IDirect3DDevice9* device, LPCWSTR imagePath, D3DXVECTOR2 position, D3DXVECTOR2 size, D3DCOLOR color)
{
	m_device = device;
	m_position = position;
	m_size = size;
	m_color = color;
	LoadTexture(imagePath);

}

Image::~Image()
{
}

void Image::Draw()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);

	auto position = D3DXVECTOR3(m_position.x, m_position.y, 0.0f);
	m_sprite->Draw(m_texture, NULL, NULL, &position, m_color);

	m_sprite->End();
}

void Image::SetSize(D3DXVECTOR2 size, int clientWidth, int clienHeight, int renderWidth, int renderHeight)
{

	float wR = ((float)clientWidth / renderWidth);
	float hR = ((float)clienHeight / renderHeight);

	float scaleX = (float)size.x / (float)m_size.x;
	float scaleY = (float)size.y / (float)m_size.y;

	D3DXMATRIX mat;

	D3DXMatrixScaling(&mat, scaleX, scaleY, 1.0f);
	mat._41 = m_position.x;
	mat._42 = m_position.y;

	m_sprite->SetTransform(&mat);
}

bool Image::LoadTexture(LPCWSTR imagePath)
{
	HRESULT result = D3DXCreateTextureFromFile(m_device, imagePath, &m_texture);

	if (FAILED(result))
	{
		return false;
	}

	HRESULT result2 = D3DXCreateSprite(m_device, &m_sprite);

	if (FAILED(result2))
	{
		return false;
	}

	D3DSURFACE_DESC desc;
	m_texture->GetLevelDesc(0, &desc);
	m_size = D3DXVECTOR2(desc.Width, desc.Height);

	return true;
}
