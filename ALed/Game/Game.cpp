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

	ColoredCube* cube = new ColoredCube(Transform(D3DXVECTOR3(3.f, 3.f, 20.f),
		D3DXVECTOR3(M_PI_4, M_PI_4, M_PI_4),
		D3DXVECTOR3(1.f, 1.f, 1.f)), 0.5f,
		d3dColors::Yellow, "D:/mvita/Color.hlsl");
	tApp->CreateColoredGameObject(cube);

	ColoredCube* cube1 = new ColoredCube(Transform(D3DXVECTOR3(-3.f, 3.f, 40.f),
		D3DXVECTOR3(M_PI_4, M_PI_4, M_PI_4),
		D3DXVECTOR3(1.f, 1.f, 1.f)), 0.5f,
		d3dColors::Blue);
	tApp->CreateColoredGameObject(cube1);

	ColoredCube* cube2 = new ColoredCube(Transform(D3DXVECTOR3(3.f, -3.f, 60.f),
		D3DXVECTOR3(M_PI_4, M_PI_4, M_PI_4),
		D3DXVECTOR3(1.f, 1.f, 1.f)), 0.5f,
		d3dColors::Green);
	tApp->CreateColoredGameObject(cube2);

	LandscapeGenerator* land = new LandscapeGenerator(
		Transform(
		D3DXVECTOR3(100.f, -10.f, 5),
		D3DXVECTOR3(M_PI_2, 0.f, 0.f),
		D3DXVECTOR3(1.f, 1.f, 1.f)),
		500,305,1.f);

	LandscapeGenerator* sky = new LandscapeGenerator(
		Transform(
			D3DXVECTOR3(100.f, 50.f, 5),
			D3DXVECTOR3(-M_PI_2, 0.f, 0.f),
			D3DXVECTOR3(1.f, 1.f, 1.f)),
		500, 305, 1.f);


	ColoredCubeMesh* defMesh = new ColoredCubeMesh(1.f, d3dColors::Red);
	GenerateSpaceships* sGenerator = new GenerateSpaceships(tApp->pCamera, defMesh);
	tApp->CreateColoredGameObject(sGenerator->CreateSpaceShip());

	/*
	if (land->CreateMesh())
	{
		tApp->CreateColoredGameObject(land);
	}

	if (sky->CreateMesh())
	{
		tApp->CreateColoredGameObject(sky);
	}

	UI* playerUI = new UI(tApp->pCamera);
	tApp->pCamera->SetUI(playerUI);
	tApp->CreateColoredGameObject(playerUI);

	if (tApp->Init() == false)
	{
		return 1;
	}

	return tApp->Run();
}