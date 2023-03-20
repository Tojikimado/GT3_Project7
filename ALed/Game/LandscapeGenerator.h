#pragma once
#include <vector>
#include "ColoredGameObject.h"
#include "PerlinNoise.h"


class LandscapeGenerator : public ColoredGameObject
{
public:
	LandscapeGenerator(Transform _transform, int _XSize, int _YSize, float _Scale);

	int XSize, YSize;
	float Scale;

	bool CreateMesh();


protected:

private:
};



