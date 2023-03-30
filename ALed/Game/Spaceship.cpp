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

Spaceship::Spaceship(Transform transform, ColoredMeshRenderer* meshR)
{
	isHit = false;
	m_transform = transform;
	m_meshRenderer = meshR;
	D3DXVECTOR3* offsetPos = &m_transform.m_position;
	offsetPos->y += 1.f;
	collider = BoundingAABB(1, offsetPos, new ColoredRectangleMesh(2.f, 1.5f, 2.f));
}

Spaceship::~Spaceship()
{
}

void Spaceship::OnHit()
{
	this->b_isActive = false;
	//delete this;
}
