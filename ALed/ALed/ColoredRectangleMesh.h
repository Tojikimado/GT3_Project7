#pragma once

#include "ColoredMesh.h"
class ColoredRectangleMesh: public ColoredMesh
{


public:
	ColoredRectangleMesh();
	ColoredRectangleMesh(float height, float width, float deepth, D3DCOLOR color);
	ColoredRectangleMesh(float height, float width, float deepth);
};

