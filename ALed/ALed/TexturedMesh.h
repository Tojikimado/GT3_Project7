#pragma once
#include "Mesh.h"
using namespace d3dVertex;

class TexturedMesh : public Mesh
{
protected:
	VertexPositionTexture* vertices;
	int nbVertices;

public:
	TexturedMesh();
	TexturedMesh(VertexPositionTexture* newvertices, int size, short* indices, int indiceSize);

	VertexPositionTexture* GetVerices();
	int GetNbVertices();
	int GetVerticesSize();
};

