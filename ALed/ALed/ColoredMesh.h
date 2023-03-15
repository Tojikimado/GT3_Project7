#pragma once
#include "Mesh.h"
using namespace d3dVertex;

class ColoredMesh: public Mesh
{
protected:
	VertexPositionColor* vertices;
	int nbVertices;

public:
	ColoredMesh();
	ColoredMesh(VertexPositionColor* newvertices, int size, short* indices, int indiceSize);

	VertexPositionColor* GetVerices();
	int GetNbVertices();
	int GetVerticesSize();
};

