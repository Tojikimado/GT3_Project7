#include "Test.h"
#include "TrackPosition.h"

const DWORD d3dVertex::VertexPositionColor::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;
const DWORD d3dVertex::VertexPositionTexture::FVF = D3DFVF_XYZ | D3DFVF_TEX1;

#pragma region Test class for our D3App class


ID3DXEffect* shader;
Track* track;

Test::Test(HINSTANCE hInstance) :D3DApp(hInstance)
{
}

Test::~Test()
{

}

bool Test::Init()
{
	/*
	if (D3DApp::Init() == false)
	{
		return false;
	}
	*/
	/*
	if (pCamera == nullptr)
	{
		pCamera = new Camera(m_pDevice3D, m_uiClientWidth, m_uiClientHeight, Transform(D3DXVECTOR3(0.f, 0.f, -10.0f), D3DXVECTOR3(0.f, 0.f, 0.f), D3DXVECTOR3(1.f, 1.f, 1.f)));
	}
	*/
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
	
	/*TexturedMeshRenderer* brickCubeRenderer = new TexturedMeshRenderer(new TexturedMesh());
	brickCube = new TexturedGameObject(Transform(D3DXVECTOR3(0.f, 2.f, 1.f), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)), brickCubeRenderer);
	brickCube = new TexturedGameObject(Transform(D3DXVECTOR3(0.f, 2.f, 1.f), D3DXVECTOR3(M_PI_4, M_PI_4, 0), D3DXVECTOR3(1.f, 1.f, 1.f)), brickCubeRenderer, pCamera);
	brickCube->Init(m_pDevice3D);
	*/

	for (ColoredGameObject* coloredGO : v_coloredGameObjects)
	{
		coloredGO->Init(m_pDevice3D);
	}

	//D3DXCreateEffect(m_pDevice3D, , , nullptr, nullptr, D3DXSHADER_PACKMATRIX_COLUMNMAJOR, nullptr, &shader, nullptr);

	m_pDevice3D->SetRenderState(D3DRS_LIGHTING, false);
	m_pDevice3D->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);

	return true;
}

void Test::Update(float dt)
{
	this->D3DApp::Update(dt);
	for (Track* gameObject : v_tracks) {
		gameObject->Update(dt);
	}
	pTrack->Update(dt);
	D3DApp::Update(dt);
	pCamera->Update(dt);

	if (InputController::Get()->IsKey(InputController::Get()->m_controls["Forward"]))
	{
		std::string a = to_string(InputController::Get()->m_keys[InputController::Get()->m_controls["Forward"]]);
		std::wstring b = wstring(a.begin(), a.end());
		OutputDebugString(b.c_str());
		InputController::Get()->Update();
	}
}

void Test::Render()
{
	this->D3DApp::Render();
}

#pragma endregion