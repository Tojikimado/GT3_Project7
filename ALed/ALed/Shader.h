#pragma once
#include "d3dUtil.h"
#include <string>
#include <map>

class Shader
{
public : 
	Shader(std::string _shaderFilePath);
	~Shader();

	virtual void Init(IDirect3DDevice9* m_pDevice3D);

	virtual void SetAndCommitChanges(IDirect3DDevice9* m_pDevice3D);

	//shader
	LPD3DXEFFECT m_effect = nullptr;
	std::string m_shaderFilePath;

};

