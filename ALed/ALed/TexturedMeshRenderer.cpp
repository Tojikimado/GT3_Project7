#include "TexturedMeshRenderer.h"

TexturedMeshRenderer::TexturedMeshRenderer(TexturedMesh* mesh)
{
	texturedMesh = mesh;
}

TexturedMeshRenderer::~TexturedMeshRenderer()
{
	delete[] texturedMesh;
	delete[] vectorBuffer;
	delete[] indexBuffer;
	delete[] texture;
}

void TexturedMeshRenderer::Init(IDirect3DDevice9* m_pDevice3D)
{
	// Création d'un vertex buffer pour stocker les vertices d'une figure
	m_pDevice3D->CreateVertexBuffer(texturedMesh->GetVerticesSize(), 0,
		d3dVertex::VertexPositionTexture::FVF, D3DPOOL_MANAGED,
		&vectorBuffer, NULL);

	// Création d'un index buffer pour stocker les indexes des triangles d'une figure
	m_pDevice3D->CreateIndexBuffer(texturedMesh->GetIndicesSize(), D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16, D3DPOOL_MANAGED,
		&indexBuffer, NULL);

	// Stock les vertices dans le vertex buffer
	VOID* pVerts;
	vectorBuffer->Lock(0, texturedMesh->GetVerticesSize(), (void**)&pVerts, 0);
	memcpy(pVerts, texturedMesh->GetVerices(), texturedMesh->GetVerticesSize());
	vectorBuffer->Unlock();

	// Stock les indexes dans l'index buffer
	VOID* pIndices;
	indexBuffer->Lock(0, texturedMesh->GetIndicesSize(), (void**)&pIndices, 0);
	memcpy(pIndices, texturedMesh->GetIndices(), texturedMesh->GetIndicesSize());
	indexBuffer->Unlock();


	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, texturedMesh->GetTexFileName(), -1, wString, 4096);
	D3DXCreateTextureFromFile(m_pDevice3D, wString, &texture);
}

void TexturedMeshRenderer::Render(IDirect3DDevice9* m_pDevice3D)
{
	m_pDevice3D->SetTexture(0, texture);

	m_pDevice3D->SetStreamSource(0, vectorBuffer, 0, sizeof(d3dVertex::VertexPositionTexture));
	m_pDevice3D->SetIndices(indexBuffer);

	m_pDevice3D->SetFVF(d3dVertex::VertexPositionTexture::FVF);
	m_pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, texturedMesh->GetNbVertices(), 0, texturedMesh->GetNbIndices());
}