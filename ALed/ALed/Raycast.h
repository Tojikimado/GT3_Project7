#pragma once
#include "d3dUtil.h"
#include "CollisionHandler.h"
#include <vector>

class Raycast
{
public : 

	float distance = 500.f;
	float step = 5.f;

	bool SingleRayCast(int x, int y, const BoundingAABB spaceships_collider);

	static Raycast* Get();
};

