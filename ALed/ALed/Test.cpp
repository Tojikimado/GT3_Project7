#include "Test.h"
#include "ColoredCubeMesh.h"
#include "ColoredSlopeMesh.h"
#include "Camera.h"


const DWORD d3dVertex::VertexPositionColor::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;
const DWORD d3dVertex::VertexPositionTexture::FVF = D3DFVF_XYZ | D3DFVF_TEX1;

#pragma region Test class for our D3App class


IDirect3DVertexBuffer9* VB;
IDirect3DIndexBuffer9* IB;

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

	ColoredSlopeMesh* meshTest = new ColoredSlopeMesh(2.f,1.f,1.f);

	// Cr�ation d'un vertex buffer pour stocker les vertices d'une figure
	m_pDevice3D->CreateVertexBuffer(meshTest->GetVerticesSize(), 0,
		d3dVertex::VertexPositionColor::FVF, D3DPOOL_MANAGED,
		&VB, NULL);

	// Cr�ation d'un index buffer pour stocker les indexes des triangles d'une figure
	m_pDevice3D->CreateIndexBuffer(meshTest->GetIndicesSize(), D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16, D3DPOOL_MANAGED,
		&IB, NULL);

	// Stock les vertices dans le vertex buffer
	VOID* pVerts;
	VB->Lock(0, meshTest->GetVerticesSize(), (void**)&pVerts, 0);
	memcpy(pVerts, meshTest->GetVerices(), meshTest->GetVerticesSize());
	VB->Unlock();

	// Stock les indexes dans l'index buffer
	VOID* pIndices;
	IB->Lock(0, meshTest->GetIndicesSize(), (void**)&pIndices, 0);
	memcpy(pIndices, meshTest->GetIndices(), meshTest->GetIndicesSize());
	IB->Unlock();


	if (pCamera == nullptr)
	{
		pCamera = new Camera(m_uiClientWidth, m_uiClientHeight, D3DXVECTOR3(0.f, 0.f, -5.0f), D3DXVECTOR3(0.f, 0.f, 1.0f));
		pCamera->SetTransform(m_pDevice3D);
	}

	//D3DXMATRIX view;
	//D3DXMATRIX proj;

	////SET VIEW (transform of all the objects, 'how they appear to the camera')
	//D3DXVECTOR3 position = D3DXVECTOR3(0.0f, 0.0f, -5.0f);
	//D3DXVECTOR3 target = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	//D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//D3DXMatrixLookAtLH(&view, &position, &target, &up);
	//m_pDevice3D->SetTransform(D3DTS_VIEW, &view);

	////SET PROJECTION ('camera')
	//D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI / 4,
	//	static_cast<float>(m_uiClientWidth) / m_uiClientHeight,
	//	1.0f, 1000.f);
	//m_pDevice3D->SetTransform(D3DTS_PROJECTION, &proj);

	//
	m_pDevice3D->SetRenderState(D3DRS_LIGHTING, false);
	m_pDevice3D->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);

	return true;
}

void Test::Update(float dt)
{
	pCamera->Update();
}

void Test::Render()
{
	m_pDevice3D->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, d3dColors::Black, 1.0f, 0);

	m_pDevice3D->BeginScene();

	m_pDevice3D->SetStreamSource(0, VB, 0, sizeof(d3dVertex::VertexPositionColor));
	m_pDevice3D->SetIndices(IB);
	m_pDevice3D->SetFVF(d3dVertex::VertexPositionColor::FVF);
	m_pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 6, 0, 2);

	m_pDevice3D->EndScene();

	m_pDevice3D->Present(0, 0, 0, 0);
}

#pragma endregion