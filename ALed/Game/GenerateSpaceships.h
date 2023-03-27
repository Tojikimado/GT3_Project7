#pragma once
#include "Spaceship.h"
#include <Camera.h>
#include <stdlib.h>
class GenerateSpaceships
{
private:
	Camera* pCamera;
	ColoredMesh* sMesh;
	float generationCooldown = 4.f;
	float currentCooldown = 0.f;
public:
	GenerateSpaceships(Camera* camera, ColoredMesh* mesh);

	Spaceship* CreateSpaceShip();

	Spaceship* Update(float dt);

};

