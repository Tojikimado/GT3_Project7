#pragma once
#include "BoundingSphere.h"
#include "BoundingAABB.h"

class CollisionHandler
{
public :

	CollisionHandler();
	~CollisionHandler();

	//CollisionHandler* GetInstance();

	bool Sphere_Vs_Sphere(const BoundingSphere& _sphere, const BoundingSphere& _other);

	bool Sphere_Vs_Point(const BoundingSphere& _sphere, const D3DXVECTOR3& _other);

	bool AABB_Vs_AABB(const BoundingAABB& _box, const BoundingAABB& _other);

	bool AABB_Vs_Point(const BoundingAABB& _box, const D3DXVECTOR3& _other);

	bool AABB_Vs_Sphere(const BoundingAABB& _box, const BoundingSphere& _other);

	bool RayBoxIntersect(const BoundingAABB& _box, D3DXVECTOR3* pPoint, D3DXVECTOR3* pDir, D3DXVECTOR3* oIntersect, FLOAT* oDist);

	const float GetDistance(D3DXVECTOR3 _A, D3DXVECTOR3 _B);
	
	static CollisionHandler* Get();
};

