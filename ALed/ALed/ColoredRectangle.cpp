#include "ColoredRectangle.h"
#include "ColoredRectangleMesh.h"


ColoredRectangle::ColoredRectangle()
{
}

ColoredRectangle::ColoredRectangle(Transform transform, Camera* camera)
{
	m_transform = transform;
	ColoredRectangleMesh* mesh = new ColoredRectangleMesh();
	m_meshRenderer = new ColoredMeshRenderer(mesh);
	m_camera = camera;
}

ColoredRectangle::ColoredRectangle(Transform transform, Camera* camera, float width, float height, float deapth, D3DCOLOR color)
{
	m_transform = transform;
	ColoredRectangleMesh* mesh = new ColoredRectangleMesh(width, height, deapth, color);
	m_meshRenderer = new ColoredMeshRenderer(mesh);
	m_camera = camera;
}

