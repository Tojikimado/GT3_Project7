#pragma once
#include "Spaceship.h"
#include <Camera.h>
#include <stdlib.h>
class GenerateSpaceships
{
private:
	Camera* pCamera;
	ColoredMesh* sMesh;
public:
	GenerateSpaceships(Camera* camera, ColoredMesh* mesh);

	Spaceship* CreateSpaceShip();

};

