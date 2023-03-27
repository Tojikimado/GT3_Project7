#include "Shader.h"


Shader::Shader(std::string _shaderFilePath) : m_shaderFilePath(_shaderFilePath)
{
}

Shader::~Shader()
{
}

void Shader::Init(IDirect3DDevice9* m_pDevice3D)
{
	// set the shader 
	HRESULT hr = D3DXCreateEffectFromFileA(m_pDevice3D, m_shaderFilePath.c_str(), NULL, NULL, D3DXSHADER_PACKMATRIX_COLUMNMAJOR | D3DXSHADER_DEBUG, NULL, &m_effect, NULL);

	if (hr == D3D_OK)
	{
		m_techniqueHandle = m_effect->GetTechniqueByName("Default");
		m_effect->SetTechnique(m_techniqueHandle);
	}
}

void Shader::SetAndCommitChanges(IDirect3DDevice9* m_pDevice3D)
{

}


