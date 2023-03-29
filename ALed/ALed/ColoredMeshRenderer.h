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
	D3DMATERIAL9* m_materials = nullptr;
	DWORD m_numMaterials = 0;
	std::string m_xFilePath; 

	//shader
	Shader* m_shader;

public:
	ColoredMeshRenderer(std::string _xFile, std::string _shaderFilePath);
	ColoredMeshRenderer(std::string _xFile);

	ColoredMeshRenderer(ColoredMesh* mesh, std::string _shaderFilePath);
	ColoredMeshRenderer(ColoredMesh* mesh);
	~ColoredMeshRenderer();

	void Init(IDirect3DDevice9* pDevice3D) override;
	bool InitMeshFromXFile(IDirect3DDevice9* pDevice3D);
	void Render(IDirect3DDevice9* pDevice3D,D3DXMATRIX _worldMatrix) override;
};

