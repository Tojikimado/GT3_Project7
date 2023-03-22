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
	if (D3DApp::Init() == false)
	{
		return false;
	}


	if (pCamera == nullptr)
	{
		pCamera = new Camera(m_pDevice3D, m_uiClientWidth, m_uiClientHeight, Transform(D3DXVECTOR3(0.f, 0.f, -10.0f), D3DXVECTOR3(0.f, 0.f, 0.f), D3DXVECTOR3(1.f, 1.f, 1.f)));
	}

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

	//ColoredSlopeMesh* testMesh = new ColoredSlopeMesh(
	//	1, 1, 1, // Size
	//	d3dColors::CornFlowerBlue, // Color
	//	false, true // Orientation
	//);
	//ColoredMeshRenderer* testRenderer = new ColoredMeshRenderer(testMesh);
	//this->CreateColoredGameObject(new ColoredGameObject(
	//	Transform(
	//		D3DXVECTOR3(0, 0, 4.f),
	//		D3DXVECTOR3(0, M_PI_4, 0),
	//		D3DXVECTOR3(1.f, 1.f, 1.f)
	//	),
	//	testRenderer));
	
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
	for (Track* gameObject : v_tracks) {
		gameObject->Update(dt);
	}
	pCamera->Update(/*dt*/);
}

void Test::Render()
{
	this->D3DApp::Render();
}

LRESULT Test::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		} break;

		case WM_INPUT:
		{
			UINT dwSize;
			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));
			LPBYTE lpb = new BYTE[dwSize];
			if (lpb == NULL)
				return 0;
			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUT));
			RAWINPUT* raw = (RAWINPUT*)lpb;
			if (raw->header.dwType == RIM_TYPEKEYBOARD)
			{
				if (raw->data.keyboard.Message == WM_KEYDOWN || raw->data.keyboard.Message == WM_SYSKEYDOWN)
				{
					std::string information =
						"Make Code - " + std::to_string(raw->data.keyboard.MakeCode) +
						"; Flag - " + std::to_string(raw->data.keyboard.Flags) +
						"; Reserved - " + std::to_string(raw->data.keyboard.Reserved) +
						"; Extra Information - " + std::to_string(raw->data.keyboard.ExtraInformation) +
						"; Message - " + std::to_string(raw->data.keyboard.Message) +
						"; VKey - " + std::to_string(raw->data.keyboard.VKey) +
						"\n";
					OutputDebugString((LPCWSTR)information.c_str());
				}
			}
		} break;
	}
	return LRESULT();
}

#pragma endregion