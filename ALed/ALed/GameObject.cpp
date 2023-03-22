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

void GameObject::SetTransform(Transform transform)
{
	m_transform = transform;
}

bool GameObject::Init()
{
	return true;
}

void GameObject::Update(float dt)
{
}

void GameObject::Render()
{
}

