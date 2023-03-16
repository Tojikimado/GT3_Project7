#pragma once
#include "D3DApp.h"

class Camera; 

class Test : public D3DApp
{
public:
	Test(HINSTANCE hInstance);

	~Test();

	bool Init() override;
	void Update(float dt) override;
	void Render() override;

private: 

	Camera* pCamera = nullptr;
	
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

