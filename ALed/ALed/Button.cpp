#include "Button.h"

Button::Button(LPDIRECT3DDEVICE9 device)
{
	m_isPressed = false;
	m_caption = NULL;
}

Button::~Button()
{
}

bool Button::OnRender()
{
	return false;
}

void Button::OnSetFocus()
{
}

void Button::OnLostFocus()
{
}

void Button::SetCaption(char* Caption)
{
	LOGFONT lf;
	if (m_caption)
		delete m_caption;
	SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(lf), &lf, 0);
	//m_caption = new Label(lf, GetDevice());
	//m_caption->SetWidthHeight(0, 0);
	m_caption->SetCaption(Caption);
}

bool Button::SetUnpressedImage(char* File)
{
	return false;
}

bool Button::SetPressedImage(char* File)
{
	return false;
}
