#include "Label.h"


Label::Label(IDirect3DDevice9* device, D3DApp* app, std::string caption, D3DCOLOR color, DWORD format, RECT rect, bool isBg)
{
	m_device = device;
	m_caption = caption;
	m_color = color;
	m_format = format;
	if (!m_font)
	{
		D3DXCreateFontA(device, 22, 0, FW_NORMAL, 1, false,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
			FF_DONTCARE, "Arial", &m_font);
	}
	if (!m_texture && !m_sprite)
	{
		LoadTexture(L"../background.jpg", isBg);
	}
	SetRect(rect.left, rect.top, rect.right, rect.bottom);
	SetSize(app);

}

Label::~Label()
{
	if (m_font)
		m_font->Release();
}

bool Label::OnRender()
{
	if (m_font != nullptr)
	{
		m_sprite->Begin(D3DXSPRITE_ALPHABLEND);

		auto pos = D3DXVECTOR3(0, 0, 0);
		m_sprite->Draw(m_texture, NULL, NULL, &pos, 0xFFFFFFFF);
		m_font->DrawTextA(m_sprite, m_caption.c_str(), -1, &m_rect, m_format, m_color);

		m_sprite->End();
	}
	return true;
}

void Label::SetCaption(std::string caption)
{
	m_caption = caption;
}

std::string Label::GetCaption()
{
	return m_caption;
}

void Label::SetColor(D3DXCOLOR color)
{
	m_color = color;
}

D3DXCOLOR Label::GetColor()
{
	return m_color;
}

void Label::SetFormat(DWORD format)
{
	m_format = format;
}

DWORD Label::GetFormat()
{
	return m_format;
}

void Label::SetRect(int left, int top, int right, int bottom)
{
	m_rect.left = left;
	m_rect.top = top;
	m_rect.right = right;
	m_rect.bottom = bottom;
}

RECT Label::GetRect()
{
	return m_rect;
}

void Label::SetSize(D3DApp* app)
{
	float wR = ((float)app->GetRenderWidth() / (float)app->GetClientWidth());
	float hR = ((float)app->GetRenderHeight() / (float)app->GetClientHeight());

	D3DXMATRIX mat;

	D3DXMatrixScaling(&mat, wR, hR, 1.0f);

	m_sprite->SetTransform(&mat);
}

bool Label::LoadTexture(LPCWSTR imagePath, bool isBg)
{
	if (isBg)
	{
		HRESULT result = D3DXCreateTextureFromFile(m_device, imagePath, &m_texture);

		if (FAILED(result))
		{
			return false;
		}
	}
	else
	{
		m_texture == NULL;
	}
	
	HRESULT result2 = D3DXCreateSprite(m_device, &m_sprite);

	if (FAILED(result2))
	{
		return false;
	}

	return true;
}

void Label::Update(HWND hwnd, std::string action)
{
	m_mousePos.x = InputController::Get()->GetMouseX();
	m_mousePos.y = InputController::Get()->GetMouseY();

	ScreenToClient(hwnd, &m_mousePos);

	if (InputController::Get()->IsKeyDown(VK_RBUTTON))
	{
		if (m_mousePos.x > m_rect.left && m_mousePos.x < m_rect.right &&
			m_mousePos.y > m_rect.top && m_mousePos.y < m_rect.bottom)
		{
			if (action == "Play") {
				OutputDebugStringA("Play");
			}
			else if (action == "Quit")
			{
				OutputDebugStringA("Quit");
			}
		}
	}
}
