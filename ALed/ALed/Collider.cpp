#include "Collider.h"
#include "BoundingSphere.h"

Collider::Collider()
{
}

Collider::Collider(int _collisionType, D3DXVECTOR3* _position) :
	m_type(_collisionType), m_position(_position)
{

}

D3DXVECTOR3 Collider::GetPosition() const
{
	return *m_position;
}
