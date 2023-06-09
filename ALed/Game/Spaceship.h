#pragma once
#include <ColoredGameObject.h>
#include <BoundingAABB.h>
#include "ScoreManager.h"

class Spaceship : public ColoredGameObject
{
private:
	bool isHit;
	
public:
	Spaceship();
	Spaceship(Transform transform, ColoredMeshRenderer* mesh);
	~Spaceship();
	BoundingAABB collider;
	void OnHit();
};

