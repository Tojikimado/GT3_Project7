#pragma once
#include "MeshRenderer.h"
#include "TexturedMesh.h"
class TexturedMeshRenderer : public MeshRenderer
{
protected:
	TexturedMesh* texturedMesh;
	IDirect3DVertexBuffer9* vectorBuffer;
	IDirect3DIndexBuffer9* indexBuffer;
	IDirect3DTexture9* texture;

public:
	TexturedMeshRenderer(TexturedMesh* mesh);
	~TexturedMeshRenderer();

	void Init(IDirect3DDevice9* m_pDevice3D) override;
	void Render(IDirect3DDevice9* m_pDevice3D) override;
};

