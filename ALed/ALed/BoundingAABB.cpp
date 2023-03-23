#include "BoundingAABB.h"

BoundingAABB::BoundingAABB(int _collisionType, D3DXVECTOR3* _position, ColoredMesh* _mesh):
Collider(_collisionType, _position)
{
	m_dimensions = SetDimensions(_mesh);
}

BoundingAABB::BoundingAABB(int _collisionType, D3DXVECTOR3* _position, TexturedMesh* _mesh):
Collider(_collisionType, _position)
{
	m_dimensions = SetDimensions(_mesh);
}

d3dCollision::WidhtHeightDepth BoundingAABB::SetDimensions(ColoredMesh* _mesh)
{
	float maxWidth = _mesh->GetVertices()[0].x;
	float maxHeight = _mesh->GetVertices()[0].y;
	float maxDepth = _mesh->GetVertices()[0].z;

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVertices()[i].x;
		if (tmp > maxWidth)
		{
			maxWidth = tmp;
		}
	}

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVertices()[i].y;
		if (tmp > maxHeight)
		{
			maxHeight = tmp;
		}
	}

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVertices()[i].z;
		if (tmp > maxDepth)
		{
			maxDepth = tmp;
		}
	}

	float minWidth = _mesh->GetVertices()[0].x;
	float minHeight = _mesh->GetVertices()[0].y;
	float minDepth = _mesh->GetVertices()[0].z;

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVertices()[i].x;
		if (tmp < minWidth)
		{
			minWidth = tmp;
		}
	}

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVertices()[i].y;
		if (tmp < minHeight)
		{
			minHeight = tmp;
		}
	}

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVertices()[i].z;
		if (tmp < minDepth)
		{
			minDepth = tmp;
		}
	}

	return d3dCollision::WidhtHeightDepth(maxWidth, maxHeight, maxDepth,
		minWidth, minHeight, minDepth);
}

d3dCollision::WidhtHeightDepth BoundingAABB::SetDimensions(TexturedMesh* _mesh)
{
	float maxWidth = _mesh->GetVerices()[0].x;
	float maxHeight = _mesh->GetVerices()[0].y;
	float maxDepth = _mesh->GetVerices()[0].z;

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVerices()[i].x;
		if (tmp > maxWidth)
		{
			maxWidth = tmp;
		}
	}

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVerices()[i].y;
		if (tmp > maxHeight)
		{
			maxHeight = tmp;
		}
	}

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVerices()[i].z;
		if (tmp > maxDepth)
		{
			maxDepth = tmp;
		}
	}

	float minWidth = _mesh->GetVerices()[0].x;
	float minHeight = _mesh->GetVerices()[0].y;
	float minDepth = _mesh->GetVerices()[0].z;

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVerices()[i].x;
		if (tmp < minWidth)
		{
			minWidth = tmp;
		}
	}

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVerices()[i].y;
		if (tmp < minHeight)
		{
			minHeight = tmp;
		}
	}

	for (int i = 1; i < _mesh->GetNbVertices(); i++)
	{
		float tmp = _mesh->GetVerices()[i].z;
		if (tmp < minDepth)
		{
			minDepth = tmp;
		}
	}

	return d3dCollision::WidhtHeightDepth(maxWidth, maxHeight, maxDepth,
		minWidth, minHeight, minDepth);
}

float BoundingAABB::MaxX() const
{
	return m_dimensions.maxX + GetPosition().x;
}

float BoundingAABB::MinX() const
{
	return m_dimensions.minX - GetPosition().x;
}

float BoundingAABB::MaxY() const
{
	return m_dimensions.maxY + GetPosition().y;
}

float BoundingAABB::MinY() const
{
	return m_dimensions.minY - GetPosition().y;
}

float BoundingAABB::MaxZ() const
{
	return m_dimensions.maxZ + GetPosition().z;
}

float BoundingAABB::MinZ() const
{
	return m_dimensions.minZ - GetPosition().z;
}



