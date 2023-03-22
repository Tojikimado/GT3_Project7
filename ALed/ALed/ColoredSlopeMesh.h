#pragma once
#include "ColoredMesh.h"
#include "Transform.h"

class ColoredSlopeMesh : public ColoredMesh
{


public:
	ColoredSlopeMesh();
	ColoredSlopeMesh(float width, float height, float deepth, D3DCOLOR color, bool vOrientation, bool hOrientation);
	ColoredSlopeMesh(float width, float height, float deepth);
};

