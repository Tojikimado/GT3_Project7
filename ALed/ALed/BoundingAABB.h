#pragma once
#include "Collider.h"
#include "ColoredMesh.h"
#include "TexturedMesh.h"

class BoundingAABB : public Collider
{
public : 

	BoundingAABB(int _collisionType, D3DXVECTOR3* _position, ColoredMesh* _mesh);
	BoundingAABB(int _collisionType, D3DXVECTOR3* _position, TexturedMesh* _mesh);

	d3dCollision::WidhtHeightDepth SetDimensions(ColoredMesh* _mesh);

	d3dCollision::WidhtHeightDepth SetDimensions(TexturedMesh* _mesh);
	
	float MaxX() const;
	float MinX() const;
	float MaxY() const;
	float MinY() const;
	float MaxZ() const;
	float MinZ() const;

protected : 

	d3dCollision::WidhtHeightDepth m_dimensions;

};

