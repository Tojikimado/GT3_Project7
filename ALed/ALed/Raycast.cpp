#include "Raycast.h"

bool Raycast::SingleRayCast(int x, int y, const BoundingAABB spaceships_colliders)
{
	for (float f = 5.f; f < 500.f; f = f + step)
	{
		D3DXVECTOR3 pointPos = D3DXVECTOR3(x, y, f);
		
		if (CollisionHandler::Get()->AABB_Vs_Point(spaceships_colliders, pointPos))
		{
			return true;
		}
	}
	return false;
}

Raycast* Raycast::Get()
{
	static Raycast raycast;

	return &raycast;
}

