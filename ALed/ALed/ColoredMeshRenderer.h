#pragma once
#include "MeshRenderer.h"
#include "ColoredMesh.h"
#include <string>
#include "STimer.h"

class ColoredMeshRenderer: public MeshRenderer
{
protected:
	ColoredMesh* coloredMesh;
	IDirect3DVertexBuffer9* vectorBuffer;
	IDirect3DIndexBuffer9* indexBuffer;

	//shader
	LPD3DXEFFECT m_effect;
	D3DXHANDLE m_techniqueHandle;
	//
	D3DXHANDLE m_handlevar;
	//

public:
	ColoredMeshRenderer(ColoredMesh* mesh, std::string _shaderFilePath);
	ColoredMeshRenderer(ColoredMesh* mesh);
	~ColoredMeshRenderer();
	void Init(IDirect3DDevice9* m_pDevice3D) override;
	void Render(IDirect3DDevice9* m_pDevice3D) override;

	std::string m_shaderFilePath;

};

