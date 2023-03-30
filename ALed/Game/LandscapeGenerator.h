#pragma once
#include <vector>
#include <random>
#include "ColoredGameObject.h"
#include "Noise.h"

class LandscapeGenerator : public ColoredMesh
{
public:
	LandscapeGenerator();
	LandscapeGenerator(int _XSize, int _YSize, float _Scale);

	int XSize, YSize;
	float Scale;

	bool CreateMesh();


protected:

private:
};



