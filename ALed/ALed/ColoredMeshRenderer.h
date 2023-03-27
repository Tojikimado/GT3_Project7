#pragma once
#include "MeshRenderer.h"
#include "ColoredMesh.h"
#include <string>
#include "STimer.h"
#include "Shader.h"

class ColoredMeshRenderer: public MeshRenderer
{
protected:
	ColoredMesh* coloredMesh;
	IDirect3DVertexBuffer9* vectorBuffer;
	IDirect3DIndexBuffer9* indexBuffer;

	//x file
	LPD3DXMESH m_mesh = nullptr;
	std::string* m_xFilePath = nullptr; 

	//shader
	LPD3DXEFFECT m_effect;
	D3DXHANDLE m_techniqueHandle;

	class Shader* m_shader;

public:
	ColoredMeshRenderer(std::string _xFile, std::string _shaderFilePath);
	ColoredMeshRenderer(std::string _xFile);

	ColoredMeshRenderer(ColoredMesh* mesh, std::string _shaderFilePath);
	ColoredMeshRenderer(ColoredMesh* mesh);
	~ColoredMeshRenderer();

	void Init(IDirect3DDevice9* pDevice3D) override;
	void InitMeshFromXFile(IDirect3DDevice9* pDevice3D);
	void Render(IDirect3DDevice9* pDevice3D) override;

};

