#include "ColoredCube.h"

ColoredCube::ColoredCube(Transform transform, Camera* camera) : ColoredRectangle(transform, camera)
{
}

ColoredCube::ColoredCube(Transform transform, Camera* camera, float size, D3DCOLOR color) : ColoredRectangle(transform, camera, size, size, size, color)
{
}
