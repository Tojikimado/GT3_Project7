#pragma once
#include "MeshRenderer.h"
#include "ColoredMesh.h"

class ColoredMeshRenderer: public MeshRenderer
{
protected:
	ColoredMesh* coloredMesh;
	IDirect3DVertexBuffer9* vectorBuffer;
	IDirect3DIndexBuffer9* indexBuffer;

public:
	ColoredMeshRenderer(ColoredMesh* mesh);
	void Init(IDirect3DDevice9* m_pDevice3D) override;
	void Render(IDirect3DDevice9* m_pDevice3D) override;
};

