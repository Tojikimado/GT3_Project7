// Game.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Game.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	std::srand(time(NULL));

    MainScene* tApp = new MainScene(hInstance);

	if (tApp->D3DApp::Init() == false)
	{
		return 1;
	}
	

	if (tApp->Init() == false)
	{
		return 1;
	}

	return tApp->Run();
}