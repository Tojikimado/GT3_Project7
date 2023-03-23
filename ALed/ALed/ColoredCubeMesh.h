#pragma once
#include "ColoredRectangleMesh.h"
#include <string>

class ColoredCubeMesh: public ColoredRectangleMesh
{
public:
	ColoredCubeMesh();
	ColoredCubeMesh(float size);
	ColoredCubeMesh(float size, D3DCOLOR color);
	ColoredCubeMesh(float size, D3DCOLOR color, std::string _shaderFilePath);
};

