// Game.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Game.h"
#include "Test.h"
#include "LandscapeGenerator.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    Test* tApp = new Test(hInstance);

	/*
	tApp->CreateColoredGameObject(new ColoredCube(Transform(D3DXVECTOR3(3.f, 3.f, 3.f), 
		D3DXVECTOR3(M_PI_4, M_PI_4, M_PI_4), 
		D3DXVECTOR3(1.f, 1.f, 1.f)),0.5f, 
		d3dColors::Yellow));
		*/

	LandscapeGenerator* land = new LandscapeGenerator(
		Transform(
		D3DXVECTOR3(0.f, 0.f, 5.f),
		D3DXVECTOR3(0.f, 0.f, 0.f),
		D3DXVECTOR3(1.f, 1.f, 1.f)),
		6,15,1.f);

	land->CreateMesh();

	if (land->CreateMesh())
	{
		tApp->CreateColoredGameObject(land);
	}
	

	if (tApp->Init() == false)
	{
		return 1;
	}

	return tApp->Run();
}