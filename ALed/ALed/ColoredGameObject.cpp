#include "ColoredGameObject.h"

ColoredGameObject::ColoredGameObject()
{
}

ColoredGameObject::ColoredGameObject(Transform transform, ColoredMeshRenderer* meshRenderer)
{
	m_transform = transform;
	SetColoredMeshRenderer(meshRenderer);
}

ColoredGameObject::~ColoredGameObject()
{
	delete m_meshRenderer;
}

void ColoredGameObject::SetColoredMeshRenderer(ColoredMeshRenderer* _meshRenderer)
{
	m_meshRenderer = _meshRenderer;
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
	m_pDevice3D->SetTransform(D3DTS_WORLD, &m_transform.GetWorld());
	m_meshRenderer->Render(m_pDevice3D, m_transform.GetWorld());
}
