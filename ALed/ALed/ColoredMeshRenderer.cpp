#include "ColoredMeshRenderer.h"

ColoredMeshRenderer::ColoredMeshRenderer(std::string _xFile, std::string _shaderFilePath)
{
	m_shader = new Shader(_shaderFilePath);
	m_xFilePath = &_xFile;
}

ColoredMeshRenderer::ColoredMeshRenderer(std::string _xFile)
{
	m_xFilePath = &_xFile;
}

ColoredMeshRenderer::ColoredMeshRenderer(ColoredMesh* mesh, std::string _shaderFilePath)
{
	m_shader = new Shader(_shaderFilePath);
	coloredMesh = mesh;
}

ColoredMeshRenderer::ColoredMeshRenderer(ColoredMesh* mesh)
{
	coloredMesh = mesh;
}

ColoredMeshRenderer::~ColoredMeshRenderer()
{
	delete[] vectorBuffer;
	delete[] indexBuffer;
}

void ColoredMeshRenderer::Init(IDirect3DDevice9* pDevice3D)
{
	// Création d'un vertex buffer pour stocker les vertices d'une figure
	pDevice3D->CreateVertexBuffer(coloredMesh->GetVerticesSize(), 0,
		d3dVertex::VertexPositionColor::FVF, D3DPOOL_MANAGED,
		&vectorBuffer, NULL);

	// Création d'un index buffer pour stocker les indexes des triangles d'une figure
	pDevice3D->CreateIndexBuffer(coloredMesh->GetIndicesSize(), D3DUSAGE_WRITEONLY,
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

	
	/*
	else
	{
		//set mesh from .x file 
		InitMeshFromXFile(pDevice3D);
	}
	*/
	
	// set the shader 
	if (m_shader != nullptr)
	{
		m_shader->Init(pDevice3D);
	}
}

void ColoredMeshRenderer::InitMeshFromXFile(IDirect3DDevice9* pDevice3D)
{
	std::string path = *m_xFilePath;
	HRESULT hr = D3DXLoadMeshFromXA(path.c_str(), NULL, pDevice3D, NULL, NULL,
		NULL, 0, &m_mesh);
}

void ColoredMeshRenderer::Render(IDirect3DDevice9* pDevice3D)
{
	if (m_shader != nullptr && m_shader->m_effect != nullptr)
	{
		unsigned int cPasses = 0;
		pDevice3D->SetFVF(d3dVertex::VertexPositionColor::FVF);
		pDevice3D->SetStreamSource(0, vectorBuffer, 0, sizeof(d3dVertex::VertexPositionColor));
		pDevice3D->SetIndices(indexBuffer);

		/*
		pass values
		*/

		m_shader->m_effect->Begin(&cPasses, 0);

		for (unsigned int iPass = 0; iPass < cPasses; iPass++)
		{
			m_shader->m_effect->BeginPass(iPass);

			/*
			if (m_mesh != nullptr)
			{
				m_mesh->DrawSubset(0);
			}
			*/

			pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, coloredMesh->GetNbVertices(), 0, coloredMesh->GetNbIndices() / 3);
			
			m_shader->m_effect->EndPass();
		}
		m_shader->m_effect->End();
	}
	else
	{
		pDevice3D->SetStreamSource(0, vectorBuffer, 0, sizeof(d3dVertex::VertexPositionColor));
		pDevice3D->SetIndices(indexBuffer);
		pDevice3D->SetFVF(d3dVertex::VertexPositionColor::FVF);
		pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, coloredMesh->GetNbVertices(), 0, coloredMesh->GetNbIndices());
	}	
}
