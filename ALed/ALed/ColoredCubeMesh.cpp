#include "ColoredCubeMesh.h"

ColoredCubeMesh::ColoredCubeMesh() : ColoredRectangleMesh()
{
}

ColoredCubeMesh::ColoredCubeMesh(float size) : ColoredRectangleMesh(size, size, size)
{
}

ColoredCubeMesh::ColoredCubeMesh(float size, D3DCOLOR color) : ColoredRectangleMesh(size, size, size, color)
{
}

ColoredCubeMesh::ColoredCubeMesh(float size, D3DCOLOR color, std::string _shaderFilePath) : ColoredRectangleMesh(size, size, size, color)
{
}