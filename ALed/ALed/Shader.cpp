#include "Shader.h"


Shader::Shader(std::string _shaderFilePath) : m_shaderFilePath(_shaderFilePath)
{
}

Shader::~Shader()
{
	if (m_effect != nullptr) m_effect->Release();
}

void Shader::Init(IDirect3DDevice9* m_pDevice3D)
{
	// set the shader 
	HRESULT hr = D3DXCreateEffectFromFileA(m_pDevice3D, m_shaderFilePath.c_str(), NULL, NULL, D3DXSHADER_PACKMATRIX_COLUMNMAJOR | D3DXSHADER_DEBUG, NULL, &m_effect, NULL);

	if (hr == D3D_OK)
	{
		m_effect->SetTechnique(m_effect->GetTechniqueByName("Default"));
	}
}

void Shader::SetAndCommitChanges(IDirect3DDevice9* m_pDevice3D)
{

}


