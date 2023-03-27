#include "Button.h"

Button::Button(IDirect3DDevice9* device)
{
	m_pressed = false;
	m_caption = NULL;
}

Button::~Button()
{
}

bool Button::OnRender()
{
	return true;
}

void Button::OnSetFocus()
{
}

void Button::OnLostFocus()
{
}

void Button::SetCaption(IDirect3DDevice9* device, std::string Caption)
{
	LOGFONT lf;
	if (m_caption)
		delete m_caption;
	SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(lf), &lf, 0);
	m_caption = new Label(device);
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
