#include "Test.h"

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

	d3dVertex::VertexPositionColor verts[4] =
	{
		//Front
		d3dVertex::VertexPositionColor(-1.0f,1.0f,-1.0f, d3dColors::Green),
		d3dVertex::VertexPositionColor(1.0f,1.0f,-1.0f, d3dColors::Blue),
		d3dVertex::VertexPositionColor(-1.0f,-1.0f,-1.0f, d3dColors::Red),
		d3dVertex::VertexPositionColor(1.0f,-1.0f,-1.0f, d3dColors::Yellow),
	};

	short indices[6] =
	{
		0,1,2,
		2,1,3

	};

	// 4 = number of verts ( sizeof(verts) can work ) 
	m_pDevice3D->CreateVertexBuffer(4 * sizeof(d3dVertex::VertexPositionColor), 0,
		d3dVertex::VertexPositionColor::FVF, D3DPOOL_MANAGED,
		&VB, NULL);

	m_pDevice3D->CreateIndexBuffer(36 * sizeof(short), D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16, D3DPOOL_MANAGED,
		&IB, NULL);

	VOID* pVerts;

	VB->Lock(0, sizeof(verts), (void**)&pVerts, 0);
	memcpy(pVerts, verts, sizeof(verts));
	VB->Unlock();

	VOID* pIndices;
	IB->Lock(0, sizeof(indices), (void**)&pIndices, 0);
	memcpy(pIndices, indices, sizeof(indices));
	IB->Unlock();

	D3DXMATRIX view;
	D3DXMATRIX proj;

	//SET VIEW (transform of all the objects, 'how they appear to the camera')
	D3DXVECTOR3 position = D3DXVECTOR3(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	D3DXMatrixLookAtLH(&view, &position, &target, &up);
	m_pDevice3D->SetTransform(D3DTS_VIEW, &view);

	//SET PROJECTION ('camera')
	D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI / 4,
		static_cast<float>(m_uiClientWidth) / m_uiClientHeight,
		1.0f, 1000.f);
	m_pDevice3D->SetTransform(D3DTS_PROJECTION, &proj);

	//
	m_pDevice3D->SetRenderState(D3DRS_LIGHTING, false);
	m_pDevice3D->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);

	return true;
}

void Test::Update(float dt)
{

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