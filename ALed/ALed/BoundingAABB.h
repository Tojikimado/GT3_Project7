#pragma once
#include "Collider.h"
#include "ColoredMesh.h"
#include "TexturedMesh.h"

class BoundingAABB : public Collider
{
public : 

	BoundingAABB(int _collisionType, D3DXVECTOR3* _position, ColoredMesh* _mesh);
	BoundingAABB(int _collisionType, D3DXVECTOR3* _position, TexturedMesh* _mesh);

	WidhtHeightDepth SetDimensions(ColoredMesh* _mesh);

	WidhtHeightDepth SetDimensions(TexturedMesh* _mesh);
	
	float MaxX() const;
	float MinX() const;
	float MaxY() const;
	float MinY() const;
	float MaxZ() const;
	float MinZ() const;

protected : 

	WidhtHeightDepth m_dimensions;

};

