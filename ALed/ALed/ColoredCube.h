#pragma once
#include "ColoredRectangle.h"
class ColoredCube : public ColoredRectangle
{
public:
	ColoredCube(Transform transform);
	ColoredCube(Transform transform,float size, D3DCOLOR color);

};