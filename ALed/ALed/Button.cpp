#include "Button.h"

Button::Button(IDirect3DDevice9* device, D3DApp* app, std::string caption, D3DCOLOR color, DWORD format, RECT rect)
{
	m_device = device;
	m_label = new Label(device, app, caption, color, format, rect, false);
	m_image = new Image(device, L"C:/Users/htaurand/Documents/GitHub/GT3_Project7/ALed/ALed/wall.png", D3DXVECTOR3(rect.left - 30, rect.top - 5, 0), D3DXVECTOR2(rect.right/4.5f, rect.bottom - 10), color, app);
}

Button::~Button()
{
}

void Button::Update(HWND hwnd)
{
	m_mousePos.x = InputController::Get()->GetMouseX(hwnd);
	m_mousePos.y = InputController::Get()->GetMouseY(hwnd);

	if (InputController::Get()->IsKeyDown(VK_RBUTTON))
	{
		OutputDebugStringA("Preclick\n");
		if (m_mousePos.x > m_label->GetRect().left && m_mousePos.x < m_label->GetRect().right &&
			m_mousePos.y > m_label->GetRect().top && m_mousePos.y < m_label->GetRect().bottom)
		{
			OutputDebugStringA("Click\n");
		}
	}
}

Label* Button::GetLabel()
{
	return m_label;
}

Image* Button::GetImage()
{
	return m_image;
}

