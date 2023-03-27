#include "Label.h"

Label::Label(LOGFONT font, LPDIRECT3DDEVICE9 device)
{
	D3DXCreateFont(device, font.lfWidth, font.lfHeight, font.lfWeight, 1,
		font.lfItalic, font.lfCharSet, font.lfOutPrecision,
		font.lfQuality, font.lfPitchAndFamily,
		font.lfFaceName, &m_font);
	//m_caption = "";
	m_color = D3DCOLOR_XRGB(0, 0, 0);
	m_format = DT_LEFT;
}

Label::~Label()
{
	if (m_font)
		m_font->Release();
}

bool Label::OnRender()
{
	if (m_font)
	{
		RECT Rectangle;
		D3DXVECTOR2 Vec2;
		Vec2.x = 0;
		Vec2.y = 0;
		//GetAbsolutePosition(&Vec2);
		Rectangle.left = Vec2.x;
		Rectangle.top = Vec2.y;
		Rectangle.right = 100;//GetWidth();
		Rectangle.bottom = 200;//GetHeight();
		//m_font->DrawText(NULL, m_caption, strlen(m_caption), &Rectangle,
			//m_format, m_color);
	}
	return true;
}

void Label::SetCaption(char* caption)
{
	/*if (caption && *caption)
		strcpy(m_caption, caption);
	else
		m_caption[0] = 0;*/
}

char* Label::GetCaption()
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
