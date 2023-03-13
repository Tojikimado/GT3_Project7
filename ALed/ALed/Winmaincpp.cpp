#include <Windows.h>
#include "D3DApp.h"


#pragma region Test class for our D3App class
class Test : public D3DApp
{
public:
	Test(HINSTANCE hInstance);

	~Test();

	bool Init() override;
	void Update(float dt) override;
	void Render() override;
};

Test::Test(HINSTANCE hInstance):D3DApp(hInstance)
{
}

Test::~Test()
{

}

bool Test::Init()
{
	if (D3DApp::Init() == false)
	{
		return false;
	}

	return true;
}

void Test::Update(float dt)
{

}

void Test::Render()
{
	m_pDevice3D->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, d3dColors::CornFlowerBlue, 1.0f,0);

	m_pDevice3D->Present(0, 0, 0, 0);
}

#pragma endregion

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,_In_ int nCmdShow)
{
	Test* tApp = new Test(hInstance);

	if (tApp->Init() == false)
	{
		return 1;
	}

	return tApp->Run();
}