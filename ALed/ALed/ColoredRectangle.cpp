#include "ColoredRectangle.h"
#include "ColoredRectangleMesh.h"


ColoredRectangle::ColoredRectangle()
{
}

ColoredRectangle::ColoredRectangle(Transform transform)
{
	m_transform = transform;
	ColoredRectangleMesh* mesh = new ColoredRectangleMesh();
	m_meshRenderer = new ColoredMeshRenderer(mesh);
}

ColoredRectangle::ColoredRectangle(Transform transform,float width, float height, float deapth, D3DCOLOR color)
{
	m_transform = transform;
	ColoredRectangleMesh* mesh = new ColoredRectangleMesh(width, height, deapth, color);
	m_meshRenderer = new ColoredMeshRenderer(mesh);
}

