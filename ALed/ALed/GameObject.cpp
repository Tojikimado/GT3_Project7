#include "GameObject.h"

GameObject::GameObject():m_transform(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0))
{
}

GameObject::~GameObject()
{

}

Transform GameObject::GetTransform()
{
	return m_transform;
}

void GameObject::SetColoredMeshRenderer(ColoredMeshRenderer*_meshRenderer)
{
	m_meshRenderer = _meshRenderer;
}

void GameObject::SetCamera(Camera* _camera)
{
	m_camera = _camera;
}

