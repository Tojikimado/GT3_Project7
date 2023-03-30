#include "Image.h"
#include <string>
#include <iostream>

Image::Image(IDirect3DDevice9* device, LPCWSTR imagePath, D3DXVECTOR3 position, D3DXVECTOR2 size, D3DCOLOR color, D3DApp* app)
{
	m_device = device;
	m_position = position;
	m_size = size;
	m_color = color;
	LoadTexture(imagePath);
	SetSize(size, app);
}

Image::~Image()
{
}

void Image::Draw()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);

	m_sprite->Draw(m_texture, NULL, NULL, &m_position, m_color);

	m_sprite->End();
}

void Image::SetSize(D3DXVECTOR2 size, D3DApp* app)
{
	float wR = ((float)app->GetClientWidth() / (float)app->GetRenderWidth());
	float hR = ((float)app->GetClientHeight() / (float)app->GetRenderHeight());

	float scaleX = (float)size.x / ((float)m_size.x * wR);
	float scaleY = (float)size.y / ((float)m_size.y * hR);

	D3DXMATRIX mat;

	D3DXMatrixScaling(&mat, scaleX, scaleY, 1.0f);
	mat._41 = m_position.x;
	mat._42 = m_position.y;

	m_sprite->SetTransform(&mat);
}

D3DXVECTOR2 Image::GetSize()
{
	return m_size;
}

void Image::SetColor(D3DCOLOR color)
{
	m_color = color;
}

D3DCOLOR Image::GetColor()
{
	return m_color;
}

LPD3DXSPRITE Image::GetSprite()
{
	return m_sprite;
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

void Image::SetPosition(D3DXVECTOR3 position)
{
	m_position = position;
}

D3DXVECTOR3 Image::GetPosition()
{
	return m_position;
}
