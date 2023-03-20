#pragma once
#include "ColoredGameObject.h"
class ColoredRectangle : public ColoredGameObject
{
public:
	ColoredRectangle();
	ColoredRectangle(Transform transform);
	ColoredRectangle(Transform transform, float width, float height, float deapth, D3DCOLOR color);

};

