#pragma once
#include "LandscapeGenerator.h"
#include <Camera.h>
class Landscape
{
protected:
	ColoredGameObject* m_land[4];
	ColoredGameObject* m_sky[4];
public:
	Landscape(LandscapeGenerator* land, LandscapeGenerator* sky);
	~Landscape();
	
	ColoredGameObject** GetLand();
	ColoredGameObject** GetSky();
	void Update(Camera* camera);
private:
	void MoveTerrain(int x, int z);
};

