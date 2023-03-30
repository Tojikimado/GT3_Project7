#include "Raycast.h"

bool Raycast::SingleRayCast(Camera* camera, int x, int y, const BoundingAABB spaceships_colliders, D3DXVECTOR3* cursorWorldOrigin)
{

	// Get cursor ray origin and direction
	D3DXVECTOR3* cursorWorldDirection = new D3DXVECTOR3();
	camera->GetCursorRay(cursorWorldOrigin, cursorWorldDirection, x, y);
	// Check collision
	if (CollisionHandler::Get()->RayBoxIntersect(spaceships_colliders, cursorWorldOrigin, cursorWorldDirection, nullptr, nullptr)) {
		return true;
	}
	return false;
}

Raycast* Raycast::Get()
{
	static Raycast raycast;

	return &raycast;
}

