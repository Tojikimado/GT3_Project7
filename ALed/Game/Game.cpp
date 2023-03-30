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
#include "MainScene.h"
#include "ExplosionParticle.h"


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

	if (tApp->pCamera == nullptr)
	{
		tApp->pCamera = new Camera(tApp->GetDevice(), tApp->GetClientWidth(), tApp->GetClientHeight(), Transform(D3DXVECTOR3(0.f, 0.f, -10.0f), D3DXVECTOR3(0.f, 0.f, 0.f), D3DXVECTOR3(1.f, 1.f, 1.f)));
	}
	if (tApp->pTrack == nullptr)
	{
		GenerateRandPlayerSplines randSplines = GenerateRandPlayerSplines(5);
		tApp->pTrack = new PTrack(tApp->pCamera);
	}

	//tApp->pParticleSystem = new ExplosionParticle(tApp->GetDevice(), Transform(), 1000, 5, 2.f, 0.5f, 20.f, 0.5f);

	/*if (land->CreateMesh())
	{
		tApp->CreateColoredGameObject(land);
	}

	if (sky->CreateMesh())
	{
		tApp->CreateColoredGameObject(sky);
	}*/

	UI* playerUI = new UI(tApp->pCamera);
	tApp->pCamera->SetUI(playerUI);
	tApp->CreateColoredGameObject(playerUI);

	if (tApp->Init() == false)
	{
		return 1;
	}

	return tApp->Run();
}