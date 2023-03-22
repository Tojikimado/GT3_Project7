#include "UI.h"

UI::UI()
{
}

UI::UI(Camera* camera)
{
	if (camera != nullptr) m_transform = camera->GetTransform();
	else m_transform = Transform(D3DXVECTOR3(0.f, 0.f, -10.0f), D3DXVECTOR3(0.f, 0.f, 0.f), D3DXVECTOR3(1.f, 1.f, 1.f));

	VertexPositionColor* uiVertices = new VertexPositionColor[6];
	uiVertices[0] = { -4.0f, -2.0f, 0.1f, d3dColors::DarkGrey, };
	uiVertices[1] = { -1.5f, -1.5f, 2.0f, d3dColors::DarkGrey, };
	uiVertices[2] = { 0.0f, -2.0f, 0.1f, d3dColors::DarkGrey, };
	uiVertices[3] = { 0.0f, -1.0f, 5.0f, d3dColors::DarkGrey, };
	uiVertices[4] = { 1.5f, -1.5f, 2.0f, d3dColors::DarkGrey, };
	uiVertices[5] = { 4.0f, -2.0f, 0.1f, d3dColors::DarkGrey, };

	short* uiIndices = new short[12];
	uiIndices[0] = 0; uiIndices[1] = 1; uiIndices[2] = 2;
	uiIndices[3] = 1; uiIndices[4] = 3; uiIndices[5] = 2;
	uiIndices[6] = 3; uiIndices[7] = 4; uiIndices[8] = 2;
	uiIndices[9] = 4; uiIndices[10] = 5; uiIndices[11] = 2;

	ColoredMesh* mesh = new ColoredMesh(uiVertices, 6, uiIndices, 12);
	m_meshRenderer = new ColoredMeshRenderer(mesh);
}

UI::~UI()
{
}
