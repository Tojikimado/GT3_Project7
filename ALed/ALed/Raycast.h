#pragma once
#include "d3dUtil.h"
#include "CollisionHandler.h"
#include <vector>
#include "Camera.h"

class Raycast
{
public : 

	float distance = 500.f;
	float step = 5.f;

	bool SingleRayCast(Camera* camera, int x, int y, const BoundingAABB spaceships_collider, D3DXVECTOR3* cursorWorldOrigin);

	static Raycast* Get();
};

