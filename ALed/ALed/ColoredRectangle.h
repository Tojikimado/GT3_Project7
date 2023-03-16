#pragma once
#include "ColoredGameObject.h"
class ColoredRectangle : public ColoredGameObject
{
public:
	ColoredRectangle();
	ColoredRectangle(Transform transform, Camera* camera);
	ColoredRectangle(Transform transform, Camera* camera, float width, float height, float deapth, D3DCOLOR color);

};

