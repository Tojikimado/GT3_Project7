#pragma once
#include "GameObject.h"
#include "TexturedMeshRenderer.h"
class TexturedGameObject : public GameObject
{
public:
	TexturedGameObject();
	TexturedGameObject(Transform transform, TexturedMeshRenderer* meshRenderer);
	~TexturedGameObject();

	void SetTexturedMeshRenderer(TexturedMeshRenderer* _meshRenderer);

	bool Init(IDirect3DDevice9* m_pDevice3D);
	void Update(float dt);
	void Render(IDirect3DDevice9* m_pDevice3D);

protected:
	TexturedMeshRenderer* m_meshRenderer = nullptr;
};

