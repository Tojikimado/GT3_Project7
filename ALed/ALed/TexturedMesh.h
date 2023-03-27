#pragma once
#include "Mesh.h"
#include <string>
using namespace d3dVertex;

class TexturedMesh : public Mesh
{
protected:
	VertexPositionTexture* vertices;
	int nbVertices;
	const char* texFileName;


public:
	TexturedMesh();
	TexturedMesh(const char* texFile);
	TexturedMesh(VertexPositionTexture* newvertices, int size, short* indices, int indiceSize, const char* texFile);
	~TexturedMesh();

	VertexPositionTexture* GetVerices();
	int GetNbVertices();
	int GetVerticesSize();
	const char* GetTexFileName();
};

