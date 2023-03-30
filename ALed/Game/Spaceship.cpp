#include "Spaceship.h"
#include <ColoredCubeMesh.h>

Spaceship::Spaceship()
{
	isHit = false;
	m_transform = Transform();
	ColoredCubeMesh* defMesh = new ColoredCubeMesh(1.f, d3dColors::Red);
	m_meshRenderer = new ColoredMeshRenderer(defMesh);
	collider = BoundingAABB(1, &m_transform.m_position, defMesh);
}

Spaceship::Spaceship(Transform transform, ColoredMesh* mesh)
{
	isHit = false;
	m_transform = transform;
	m_meshRenderer = new ColoredMeshRenderer(mesh);
	collider = BoundingAABB(1, &m_transform.m_position, mesh);
}

Spaceship::~Spaceship()
{
}

void Spaceship::OnHit()
{
	this->b_isActive = false;
	//delete this;
}
