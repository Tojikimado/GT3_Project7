#pragma once
#include "ColoredMesh.h"

class ColoredSlopeMesh : public ColoredMesh
{


public:
	ColoredSlopeMesh();
	ColoredSlopeMesh(float height, float width, float deepth, D3DCOLOR color);
	ColoredSlopeMesh(float height, float width, float deepth);
};

