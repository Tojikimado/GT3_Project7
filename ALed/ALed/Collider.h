#pragma once
#include <cmath>
#include "IntersectData.h"
#include "d3dUtil.h"

class Collider
{
public :
	enum
	{
		TYPE_SPHERE,
		TYPE_AABB,
		TYPE_SIZE,
	};

	Collider(int _collisionType, D3DXVECTOR3 _position);

private :

	int m_type;
	D3DXVECTOR3* m_position;
};

