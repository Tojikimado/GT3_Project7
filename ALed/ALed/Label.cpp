#include "Label.h"


Label::Label(IDirect3DDevice9* device)
{
	D3DXCreateFontA(device, 22, 0, FW_NORMAL, 1, false,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, 
		FF_DONTCARE, "Arial", &m_font);
	m_caption = "";
	m_color = d3dColors::DeepPink;
	m_format = DT_CENTER;
	m_rect.left = 0;
	m_rect.top = 0;
	m_rect.right = 100;
	m_rect.bottom = 100;
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
		m_font->DrawTextA(NULL, m_caption.c_str(), -1, &m_rect, m_format, m_color);
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
