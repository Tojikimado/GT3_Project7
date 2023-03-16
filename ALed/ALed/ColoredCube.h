#pragma once
#include "ColoredRectangle.h"
class ColoredCube : public ColoredRectangle
{
public:
	ColoredCube(Transform transform, Camera* camera);
	ColoredCube(Transform transform, Camera* camera, float size, D3DCOLOR color);

};