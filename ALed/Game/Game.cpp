// Game.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Game.h"
#include "Test.h"
#include "LandscapeGenerator.h"
#include "UI.h"
#include <Track.h>
#include "SplinePresets.h"
#include "GenerateRandPlayerSplines.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	std::srand(time(NULL));

    Test* tApp = new Test(hInstance);

	if (tApp->D3DApp::Init() == false)
	{
		return false;
	}

	if (tApp->pCamera == nullptr)
	{
		tApp->pCamera = new Camera(tApp->GetDevice(), tApp->GetClientWidth(), tApp->GetClientHeight(), Transform(D3DXVECTOR3(0.f, 0.f, -10.0f), D3DXVECTOR3(0.f, 0.f, 0.f), D3DXVECTOR3(1.f, 1.f, 1.f)));
	}
	if (tApp->pTrack == nullptr)
	{
		GenerateRandPlayerSplines randSplines = GenerateRandPlayerSplines(5);
		tApp->pTrack = new PlayerTrack(tApp->pCamera, randSplines._splineBuffer, 5);
	}
	ColoredCube* cube = new ColoredCube(Transform(D3DXVECTOR3(3.f, 3.f, 20.f),
		D3DXVECTOR3(M_PI_4, M_PI_4, M_PI_4),
		D3DXVECTOR3(1.f, 1.f, 1.f)), 0.5f,
		d3dColors::Yellow);
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
	/*Track* track = new Track(cube->GetTransform(), PlayerSplines::StraightSpline(5).spline, cube, false);
	track->StartFollow();
	tApp->CreateTrack(track);*/
	LandscapeGenerator* land = new LandscapeGenerator(
		Transform(
		D3DXVECTOR3(0.f, -10.f, 5),
		D3DXVECTOR3(M_PI_2, 0.f, 0.f),
		D3DXVECTOR3(1.f, 1.f, 1.f)),
		200,205,1.f);

	land->CreateMesh();

	if (land->CreateMesh())
	{
		tApp->CreateColoredGameObject(land);
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