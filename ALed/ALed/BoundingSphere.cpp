#include "BoundingSphere.h"

BoundingSphere::BoundingSphere(int _collisionType, D3DXVECTOR3* _position) : 
	Collider(_collisionType, _position) { m_radius = 1.0f; }

BoundingSphere::BoundingSphere(int _collisionType, D3DXVECTOR3* _position, float _radius) : 
	m_radius(_radius), Collider(_collisionType, _position){}

float BoundingSphere::GetRadius() const
{
	return 0.0f;
}

void BoundingSphere::SetRadius(float _radius)
{
	m_radius = _radius;
}
