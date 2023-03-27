#include <Windows.h>
#include "GameScene.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,_In_ int nCmdShow)
{
	GameScene* tApp = new GameScene(hInstance);

	if (tApp->Init() == false)
	{
		return 1;
	}

	return tApp->Run();
}


