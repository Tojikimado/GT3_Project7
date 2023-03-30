#include "MainScene.h"
#include <ColoredCubeMesh.h>

const DWORD d3dVertex::VertexPositionColor::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;
const DWORD d3dVertex::VertexPositionTexture::FVF = D3DFVF_XYZ | D3DFVF_TEX1;

MainScene::MainScene(HINSTANCE hInstance) : D3DApp(hInstance)
{
}

MainScene::~MainScene()
{
}

bool MainScene::Init()
{
	
	Track* track;

	if (pCamera == nullptr)
	{
		pCamera = new Camera(GetDevice(), GetClientWidth(), GetClientHeight(), Transform(D3DXVECTOR3(0.f, 0.f, -10.0f), D3DXVECTOR3(0.f, 0.f, 0.f), D3DXVECTOR3(1.f, 1.f, 1.f)));
	}

	/*
	ColoredCube* cube = new ColoredCube(Transform(D3DXVECTOR3(-2.5f, -2.5f, 3.f), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)), 0.5f, d3dColors::CornFlowerBlue);
	this->CreateColoredGameObject(cube);

	SplinePoint* testSpline = new SplinePoint[5];
	testSpline[0] = { Transform() };
	testSpline[1] = { Transform(D3DXVECTOR3(0.f, 5.f, 0.f), D3DXVECTOR3(0, 0, M_PI_4), D3DXVECTOR3(1.f, 1.f, 1.f)) };
	testSpline[2] = { Transform(D3DXVECTOR3(5.f, 5.f, 0.f), D3DXVECTOR3(0, 0, M_PI), D3DXVECTOR3(1.f, 1.f, 1.f)) };
	testSpline[3] = { Transform(D3DXVECTOR3(5.f, 0.f, 0.f), D3DXVECTOR3(0, 0, 4 * M_PI), D3DXVECTOR3(1.f, 1.f, 1.f)) };
	testSpline[4] = { Transform() };

	Spline* spline = new Spline(testSpline, 5);
	track = new Track(cube->GetTransform(), spline, cube, true);
	track->StartFollow();
	this->CreateTrack(track);

	ColoredCubeMesh* defMesh = new ColoredCubeMesh(1.f, d3dColors::Red);
	sGenerator = new GenerateSpaceships(pCamera, defMesh);
	ColoredGameObject* ufo = new ColoredGameObject(Transform(D3DXVECTOR3(0.f, 0.f, 20.f), D3DXVECTOR3(0.f, 0.f ,0.f), D3DXVECTOR3(0.01f, 0.01f, 0.01f)),new ColoredMeshRenderer("../ufo_2.x", "../Color.hlsl"));
	this->CreateColoredGameObject(ufo);

	*/

	pStateMachine = new GameStateMachine(new MainMenuState());

	for (ColoredGameObject* coloredGO : v_coloredGameObjects)
	{
		coloredGO->Init(m_pDevice3D);
	}

	m_pDevice3D->SetRenderState(D3DRS_LIGHTING, false);
	m_pDevice3D->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	
	return true;
}

void MainScene::Update(float dt)
{
	this->D3DApp::Update(dt);

	//
	if (InputController::Get()->IsKeyDown(VK_LBUTTON))
	{
		for (Spaceship* spaceship : v_spaceships)
		{
			if(spaceship->b_isActive)
			{
				D3DXVECTOR3* cursorWorldOrigin = new D3DXVECTOR3();
				bool isHit = m_pRaycast->SingleRayCast(this->pCamera, m_pInputController->GetMouseX(this->GetAppWindow()), m_pInputController->GetMouseY(this->GetAppWindow()), spaceship->collider, cursorWorldOrigin);

				if(isHit)
				{
					spaceship->OnHit();
				}
			}
		}
	}

	//

	for (Track* gameObject : v_tracks) {
		gameObject->Update(dt);
	}
	if (sGenerator != nullptr) {
		Spaceship* spaceship = sGenerator->Update(dt);
		if (spaceship != nullptr) {
			v_spaceships.push_back(spaceship);
			spaceship->Init(m_pDevice3D);
			this->CreateColoredGameObject(spaceship);
		}
	}

	pStateMachine->Update(dt);

	pTrack->Update(dt);
	D3DApp::Update(dt);
	pCamera->Update(dt);
}

void MainScene::Render()
{
	this->D3DApp::Render();
}
