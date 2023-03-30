#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{
}

CollisionHandler::~CollisionHandler()
{
}

bool CollisionHandler::Sphere_Vs_Sphere(const BoundingSphere& _sphere, const BoundingSphere& _other)
{
	float distance = GetDistance(_sphere.GetPosition(), _other.GetPosition());

	return distance < (_sphere.GetRadius() + _other.GetRadius());
}

bool CollisionHandler::Sphere_Vs_Point(const BoundingSphere& _sphere, const D3DXVECTOR3& _other)
{
	float distance = GetDistance(_sphere.GetPosition(), _other);

	return distance < _sphere.GetRadius();
}

bool CollisionHandler::AABB_Vs_AABB(const BoundingAABB& _box, const BoundingAABB& _other)
{
	return (_box.MinX() <= _other.MaxX() &&
			_box.MaxX() >= _other.MinX() &&
			_box.MinY() <= _other.MaxY() &&
			_box.MaxY() >= _other.MinY() &&
			_box.MinZ() <= _other.MaxZ() &&
			_box.MaxZ() >= _other.MinZ());
}

bool CollisionHandler::AABB_Vs_Point(const BoundingAABB& _box, const D3DXVECTOR3& _other)
{
	return (_box.MinX() <= _other.x &&
		_box.MaxX() >= _other.x &&
		_box.MinY() <= _other.y &&
		_box.MaxY() >= _other.y &&
		_box.MinZ() <= _other.y &&
		_box.MaxZ() >= _other.y);
}

bool CollisionHandler::AABB_Vs_Sphere(const BoundingAABB& _box, const BoundingSphere& _other)
{
	const float x = max(_box.MinX(), min(_other.GetPosition().x,_box.MaxX()));
	const float y = max(_box.MinY(), min(_other.GetPosition().y, _box.MaxY()));
	const float z = max(_box.MinZ(), min(_other.GetPosition().z, _box.MaxZ()));

	const float distance = sqrt(pow(x - _other.GetPosition().x, 2) +
		pow(y - _other.GetPosition().y, 2) +
		pow(z - _other.GetPosition().z, 2));

	return distance < _other.GetRadius();
}

bool CollisionHandler::RayBoxIntersect(const BoundingAABB& _box, D3DXVECTOR3* pPoint, D3DXVECTOR3* pDir, D3DXVECTOR3* oIntersectPoint, FLOAT* oDist)
{

	FLOAT tmin = 0.0f;
	FLOAT tmax = 200.f;
	D3DXVECTOR3 boxMin = D3DXVECTOR3(_box.MinX(), _box.MinY(), _box.MinZ());
	D3DXVECTOR3 boxMax = D3DXVECTOR3(_box.MaxX(), _box.MaxY(), _box.MaxZ());
	// Boucle pour x, y et z
	for (int i = 0; i < 3; i++)
	{
		if (fabs((*pDir)[i]) < FLT_EPSILON)
		{
			if ((*pPoint)[i]<boxMin[i] || (*pPoint)[i]>boxMax[i])
				return false;
		}
		else
		{
			FLOAT ood = 1.0f / (*pDir)[i];
			FLOAT t1 = (boxMin[i] - (*pPoint)[i]) * ood;
			FLOAT t2 = (boxMax[i] - (*pPoint)[i]) * ood;
			if (t1 > t2) {
				FLOAT t3 = t1;
				t1 = t2;
				t2 = t3;
			}
			tmin = max(tmin, t1);
			tmax = min(tmax, t2);
			if (tmin > tmax)
				return false;
		}
	}
	if (oIntersectPoint)
		*oIntersectPoint = *pPoint + *pDir * tmin;
	if (oDist)
		*oDist = tmin;
	return true;
}

const float CollisionHandler::GetDistance(D3DXVECTOR3 _A,D3DXVECTOR3 _B)
{
	return (float)sqrt(pow(_B.x-_A.x,2) + pow(_B.y-_A.y,2) + pow(_B.z-_A.z,2));
}

CollisionHandler* CollisionHandler::Get()
{
	static CollisionHandler collisionHandler;

	return &collisionHandler;
}
