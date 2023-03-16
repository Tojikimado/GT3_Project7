#pragma once

#include "ColoredMesh.h"
class ColoredRectangleMesh: public ColoredMesh
{


public:
	ColoredRectangleMesh();
	ColoredRectangleMesh(float width, float height, float deepth, D3DCOLOR color);
	ColoredRectangleMesh(float width, float height, float deepth);
};

