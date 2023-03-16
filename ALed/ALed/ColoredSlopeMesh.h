#pragma once
#include "ColoredMesh.h"

class ColoredSlopeMesh : public ColoredMesh
{


public:
	ColoredSlopeMesh();
	ColoredSlopeMesh(float width, float height, float deepth, D3DCOLOR color);
	ColoredSlopeMesh(float width, float height, float deepth);
};

