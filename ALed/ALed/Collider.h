#pragma once
#include "d3dUtil.h"

class Collider
{
public :
	enum
	{
		TYPE_SPHERE,
		TYPE_AABB,
	};
	Collider();
	Collider(int _collisionType, D3DXVECTOR3* _position);

	D3DXVECTOR3 GetPosition() const;

protected :
	D3DXVECTOR3* m_position;

private : 
	int m_type;

};

