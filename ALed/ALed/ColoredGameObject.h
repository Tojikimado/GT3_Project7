#pragma once
#include "GameObject.h"
#include "ColoredMeshRenderer.h"
class ColoredGameObject : public GameObject
{
public:
	ColoredGameObject();
	ColoredGameObject(Transform transform, ColoredMeshRenderer* meshRenderer);
	~ColoredGameObject();

	void SetColoredMeshRenderer(ColoredMeshRenderer* _meshRenderer);

	bool Init(IDirect3DDevice9* m_pDevice3D);
	void Update(float dt);
	void Render(IDirect3DDevice9* m_pDevice3D);

protected:
	ColoredMeshRenderer* m_meshRenderer = nullptr;

};

