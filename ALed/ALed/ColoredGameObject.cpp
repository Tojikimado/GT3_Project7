#include "ColoredGameObject.h"

ColoredGameObject::ColoredGameObject()
{
}

ColoredGameObject::ColoredGameObject(Transform transform, ColoredMeshRenderer* meshRenderer, Camera* camera)
{
	m_transform = transform;
	SetColoredMeshRenderer(meshRenderer);
	SetCamera(camera);
}

ColoredGameObject::~ColoredGameObject()
{
}

bool ColoredGameObject::Init(IDirect3DDevice9* m_pDevice3D)
{
	m_meshRenderer->Init(m_pDevice3D);
	return true;
}

void ColoredGameObject::Update(float dt)
{
}

void ColoredGameObject::Render(IDirect3DDevice9* m_pDevice3D)
{
	m_pDevice3D->SetTransform(D3DTS_WORLD, m_transform.GetWorld());
	m_meshRenderer->Render(m_pDevice3D);
}
