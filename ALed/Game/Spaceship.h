#pragma once
#include <ColoredGameObject.h>
#include <BoundingAABB.h>
class Spaceship : public ColoredGameObject
{
private:
	bool isHit;
	BoundingAABB collider;
public:
	Spaceship();
	Spaceship(Transform transform, ColoredMesh* mesh);
	~Spaceship();

	void OnHit();
};

