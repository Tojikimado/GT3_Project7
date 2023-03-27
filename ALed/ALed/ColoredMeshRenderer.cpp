#include "ColoredMeshRenderer.h"

ColoredMeshRenderer::ColoredMeshRenderer(ColoredMesh* mesh, std::string _shaderFilePath)
{
	m_shader = new Shader(_shaderFilePath);
	coloredMesh = mesh;
	m_shaderFilePath = _shaderFilePath;
}

ColoredMeshRenderer::ColoredMeshRenderer(ColoredMesh* mesh)
{
	coloredMesh = mesh;
}

ColoredMeshRenderer::~ColoredMeshRenderer()
{
	delete[] coloredMesh;
	delete[] vectorBuffer;
	delete[] indexBuffer;
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
	memcpy(pVerts, coloredMesh->GetVertices(), coloredMesh->GetVerticesSize());
	vectorBuffer->Unlock();

	// Stock les indexes dans l'index buffer
	VOID* pIndices;
	indexBuffer->Lock(0, coloredMesh->GetIndicesSize(), (void**)&pIndices, 0);
	memcpy(pIndices, coloredMesh->GetIndices(), coloredMesh->GetIndicesSize());
	indexBuffer->Unlock();

	// set the shader 
	if (m_shader != nullptr)
	{
		m_shader->Init(m_pDevice3D);
	}
}

void ColoredMeshRenderer::Render(IDirect3DDevice9* m_pDevice3D)
{
	if (m_shader != nullptr && m_shader->m_effect != nullptr)
	{
		unsigned int cPasses = 0;
		m_pDevice3D->SetStreamSource(0, vectorBuffer, 0, sizeof(d3dVertex::VertexPositionColor));
		m_pDevice3D->SetIndices(indexBuffer);
		/*
		pass values
		*/
		m_shader->m_effect->Begin(&cPasses, 0);

		for (unsigned int iPass = 0; iPass < cPasses; iPass++)
		{
			m_shader->m_effect->BeginPass(iPass);
			m_pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, coloredMesh->GetNbVertices(), 0, coloredMesh->GetNbIndices());
			m_shader->m_effect->EndPass();
		}
		m_shader->m_effect->End();
	}
	else
	{
		m_pDevice3D->SetStreamSource(0, vectorBuffer, 0, sizeof(d3dVertex::VertexPositionColor));
		m_pDevice3D->SetIndices(indexBuffer);
		m_pDevice3D->SetFVF(d3dVertex::VertexPositionColor::FVF);
		m_pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, coloredMesh->GetNbVertices(), 0, coloredMesh->GetNbIndices());
	}	
}
