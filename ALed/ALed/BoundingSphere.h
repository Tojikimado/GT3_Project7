#pragma once
#include "Collider.h"

class BoundingSphere : public Collider
{

public :
	BoundingSphere(int _collisionType, D3DXVECTOR3* _position);
	BoundingSphere(int _collisionType, D3DXVECTOR3* _position, float _radius);

	float GetRadius() const;

	void SetRadius(float _radius);

private : 
	float m_radius = 1.0f;
};

