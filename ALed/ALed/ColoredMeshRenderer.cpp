#include "ColoredMeshRenderer.h"

ColoredMeshRenderer::ColoredMeshRenderer(ColoredMesh* mesh)
{
	coloredMesh = mesh;
}

void ColoredMeshRenderer::Init(IDirect3DDevice9* m_pDevice3D)
{
	// Création d'un vertex buffer pour stocker les vertices d'une figure
	m_pDevice3D->CreateVertexBuffer(coloredMesh->GetVerticesSize(), 0,
		d3dVertex::VertexPositionColor::FVF, D3DPOOL_MANAGED,
		&vectorBuffer, NULL);

	// Création d'un index buffer pour stocker les indexes des triangles d'une figure
	m_pDevice3D->CreateIndexBuffer(coloredMesh->GetIndicesSize(), D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16, D3DPOOL_MANAGED,
		&indexBuffer, NULL);

	// Stock les vertices dans le vertex buffer
	VOID* pVerts;
	vectorBuffer->Lock(0, coloredMesh->GetVerticesSize(), (void**)&pVerts, 0);
	memcpy(pVerts, coloredMesh->GetVerices(), coloredMesh->GetVerticesSize());
	vectorBuffer->Unlock();

	// Stock les indexes dans l'index buffer
	VOID* pIndices;
	indexBuffer->Lock(0, coloredMesh->GetIndicesSize(), (void**)&pIndices, 0);
	memcpy(pIndices, coloredMesh->GetIndices(), coloredMesh->GetIndicesSize());
	indexBuffer->Unlock();

}

void ColoredMeshRenderer::Render(IDirect3DDevice9* m_pDevice3D)
{
	m_pDevice3D->SetStreamSource(0, vectorBuffer, 0, sizeof(d3dVertex::VertexPositionColor));
	m_pDevice3D->SetIndices(indexBuffer);

	// ROTATION
	static float index = 0.0f; index += 0.02f; // an ever-increasing float value
	D3DXMATRIX matRotate;    // a matrix to store the rotation for each triangle
	D3DXMatrixRotationY(&matRotate, index);    // the rotation matrix
	m_pDevice3D->SetTransform(D3DTS_WORLD, &(matRotate));    // set the world transform

	m_pDevice3D->SetFVF(d3dVertex::VertexPositionColor::FVF);
	m_pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, coloredMesh->GetNbVertices(), 0, coloredMesh->GetNbIndices());
}
