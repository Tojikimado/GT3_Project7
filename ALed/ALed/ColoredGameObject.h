#pragma once
#include "GameObject.h"
class ColoredGameObject : public GameObject
{
public:
	ColoredGameObject();
	ColoredGameObject(Transform transform, ColoredMeshRenderer* meshRenderer, Camera* camera);
	~ColoredGameObject();

	bool Init(IDirect3DDevice9* m_pDevice3D);
	void Update(float dt);
	void Render(IDirect3DDevice9* m_pDevice3D);

};

