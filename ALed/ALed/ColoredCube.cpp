#include "ColoredCube.h"

ColoredCube::ColoredCube(Transform transform) : ColoredRectangle(transform)
{
}

ColoredCube::ColoredCube(Transform transform, float size, D3DCOLOR color) : ColoredRectangle(transform, size, size, size, color)
{
}

ColoredCube::ColoredCube(Transform transform, float size, D3DCOLOR color, std::string _shaderFilePath) : ColoredRectangle(transform, size, size, size, color, _shaderFilePath)
{
}