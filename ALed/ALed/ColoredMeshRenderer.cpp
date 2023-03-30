#include "ColoredMeshRenderer.h"

ColoredMeshRenderer::ColoredMeshRenderer(std::string _xFile, std::string _shaderFilePath)
{
	m_shader = new Shader(_shaderFilePath);
	m_xFilePath = _xFile;
}

ColoredMeshRenderer::ColoredMeshRenderer(std::string _xFile)
{
	m_xFilePath = _xFile;
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

	if(InitMeshFromXFile(pDevice3D) == false)
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
	}

	// set the shader 
	if (m_shader != nullptr)
	{
		m_shader->Init(pDevice3D);
	}
}

bool ColoredMeshRenderer::InitMeshFromXFile(IDirect3DDevice9* pDevice3D)
{
	LPD3DXBUFFER tmp_buffer;
	HRESULT hr = D3DXLoadMeshFromXA(m_xFilePath.c_str(), NULL, pDevice3D, NULL, &tmp_buffer,
		NULL, &m_numMaterials, &m_mesh);

	if (hr == D3D_OK)
	{
		//int c = m_mesh->GetNumFaces();
		D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)tmp_buffer->GetBufferPointer();

		m_materials = new D3DMATERIAL9[m_numMaterials];

		for (DWORD index = 0; index < m_numMaterials; index++)
		{
			m_materials[index] = tempMaterials[index].MatD3D;
			m_materials[index].Ambient = m_materials[index].Diffuse;
		}
		tmp_buffer->Release();
			
		return true;

	}
	return false;
}

void ColoredMeshRenderer::Render(IDirect3DDevice9* pDevice3D,D3DXMATRIX _worldMatrix)
{
	if (m_shader != nullptr && m_shader->m_effect != nullptr)
	{
		unsigned int cPasses = 0;

		if (m_mesh == nullptr)
		{
			pDevice3D->SetFVF(d3dVertex::VertexPositionColor::FVF);
			pDevice3D->SetStreamSource(0, vectorBuffer, 0, sizeof(d3dVertex::VertexPositionColor));
			pDevice3D->SetIndices(indexBuffer);
		}

		m_shader->m_effect->SetMatrix("WorldViewProj",&_worldMatrix);

		m_shader->m_effect->Begin(&cPasses, 0);

		for (unsigned int iPass = 0; iPass < cPasses; iPass++)
		{
			m_shader->m_effect->BeginPass(iPass);

			if (m_mesh != nullptr)
			{
				for (DWORD index = 0; index < m_numMaterials; index++)
				{
					pDevice3D->SetMaterial(&m_materials[index]);
					m_shader->m_effect->CommitChanges();
					HRESULT hr = m_mesh->DrawSubset(index);
					int a = 0;
				}
				
			}
			else
			{
				pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, coloredMesh->GetNbVertices(), 0, coloredMesh->GetNbIndices() / 3);
			}

			m_shader->m_effect->EndPass();
		}
		m_shader->m_effect->End();
	}
	else
	{
		if (m_mesh != nullptr)
		{
			for (DWORD index = 0; index < m_numMaterials; index++)
			{
				pDevice3D->SetMaterial(&m_materials[index]);
				HRESULT hr = m_mesh->DrawSubset(index);
			}
		}
		else
		{
			pDevice3D->SetStreamSource(0, vectorBuffer, 0, sizeof(d3dVertex::VertexPositionColor));
			pDevice3D->SetIndices(indexBuffer);
			pDevice3D->SetFVF(d3dVertex::VertexPositionColor::FVF);
			pDevice3D->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, coloredMesh->GetNbVertices(), 0, coloredMesh->GetNbIndices());
		}
	}
}
