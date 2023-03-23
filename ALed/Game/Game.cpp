// Game.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Game.h"
#include "Test.h"
#include "LandscapeGenerator.h"
#include "UI.h"
#include <Track.h>
#include "SplinePresets.h"


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
	
	ColoredCube* cube = new ColoredCube(Transform(D3DXVECTOR3(3.f, 3.f, 3.f),
		D3DXVECTOR3(M_PI_4, M_PI_4, M_PI_4),
		D3DXVECTOR3(1.f, 1.f, 1.f)), 0.5f,
		d3dColors::Yellow);
	tApp->CreateColoredGameObject(cube);

	Track* track = new Track(tApp->pCamera->GetTransform(), PlayerSplines::StraightSpline(5).spline, tApp->pCamera, false);
	track->StartFollow();
	tApp->CreateTrack(track);
	/*LandscapeGenerator* land = new LandscapeGenerator(
		Transform(
		D3DXVECTOR3(0.f, -10.f, 5),
		D3DXVECTOR3(M_PI_2, 0.f, 0.f),
		D3DXVECTOR3(1.f, 1.f, 1.f)),
		100,205,1.f);

	land->CreateMesh();

	if (land->CreateMesh())
	{
		tApp->CreateColoredGameObject(land);
	}
	*/
	tApp->CreateColoredGameObject(new UI(tApp->pCamera));

	if (tApp->Init() == false)
	{
		return 1;
	}


	return tApp->Run();
}