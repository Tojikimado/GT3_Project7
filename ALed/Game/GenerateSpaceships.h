#pragma once
#include "Spaceship.h"
#include <Camera.h>
#include <stdlib.h>
class GenerateSpaceships
{
private:
	Camera* pCamera;
	ColoredMeshRenderer* sMeshR;
	float generationCooldown = 1.f;
	float currentCooldown = 0.f;
public:
	GenerateSpaceships(Camera* camera, ColoredMeshRenderer* meshR);
	~GenerateSpaceships();

	Spaceship* CreateSpaceShip();

	Spaceship* Update(float dt);

};

