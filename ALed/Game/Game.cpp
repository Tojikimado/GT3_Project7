// Game.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Game.h"
#include "GameScene.h"
#include "LandscapeGenerator.h"
#include "UI.h"
#include <Track.h>
#include "SplinePresets.h"
#include "GenerateRandPlayerSplines.h"
#include <ColoredCubeMesh.h>
#include "GenerateSpaceships.h"
#include "GameApp.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	std::srand(time(NULL));

    GameApp* tApp = new GameApp(hInstance);

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