#pragma once
#include "ColoredRectangleMesh.h"

class ColoredCubeMesh: public ColoredRectangleMesh
{
public:
	ColoredCubeMesh();
	ColoredCubeMesh(float size);
	ColoredCubeMesh(float size, D3DCOLOR color);
};

