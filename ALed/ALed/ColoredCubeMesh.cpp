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
