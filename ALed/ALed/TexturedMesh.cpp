#include "TexturedMesh.h"

TexturedMesh::TexturedMesh() {
	// Create a Cube by default
	VertexPositionTexture* cubeVertices = new VertexPositionTexture[8];
	cubeVertices[0] = { -1.0f, 1.0f, -1.0f, 0.f, 0.f, };
	cubeVertices[1] = { 1.0f, 1.0f, -1.0f,  1.f, 0.f, };
	cubeVertices[2] = { -1.0f, -1.0f, -1.0f,  0.f, 1.f, };
	cubeVertices[3] = { 1.0f, -1.0f, -1.0f, 0.f, 0.f, };
	cubeVertices[4] = { -1.0f, 1.0f, 1.0f, 0.f, 0.f, };
	cubeVertices[5] = { 1.0f, 1.0f, 1.0f, 0.f, 0.f, };
	cubeVertices[6] = { -1.0f, -1.0f, 1.0f, 0.f, 0.f, };
	cubeVertices[7] = { 1.0f, -1.0f, 1.0f, 0.f, 0.f, };

	this->vertices = cubeVertices;
	this->nbVertices = 8;

	// create the indices using an int array
	short* baseIndices = new short[36];
	baseIndices[0] = 0; baseIndices[1] = 1; baseIndices[2] = 2;   // side 1
	baseIndices[3] = 2; baseIndices[4] = 1; baseIndices[5] = 3;

	baseIndices[6] = 4; baseIndices[7] = 0; baseIndices[8] = 6;    // side 2
	baseIndices[9] = 6; baseIndices[10] = 0; baseIndices[11] = 2;

	baseIndices[12] = 7; baseIndices[13] = 5; baseIndices[14] = 6;    // side 3
	baseIndices[15] = 6; baseIndices[16] = 5; baseIndices[17] = 4;

	baseIndices[18] = 3; baseIndices[19] = 1; baseIndices[20] = 7;    // side 4
	baseIndices[21] = 7; baseIndices[22] = 1; baseIndices[23] = 5;

	baseIndices[24] = 4; baseIndices[25] = 5; baseIndices[26] = 0;    // side 5
	baseIndices[27] = 0; baseIndices[28] = 5; baseIndices[29] = 1;

	baseIndices[30] = 3; baseIndices[31] = 7; baseIndices[32] = 2;    // side 6
	baseIndices[33] = 2; baseIndices[34] = 7; baseIndices[35] = 6;

	this->indices = baseIndices;
	this->nbIndices = 36;
}

TexturedMesh::TexturedMesh(VertexPositionTexture* newvertices, int size, short* indices, int indiceSize)
{
	//memcpy(vertices, newvertices, size * sizeof(CUSTOMVERTEX));
	this->vertices = newvertices;
	this->nbVertices = size;
	this->indices = indices;
	this->nbIndices = indiceSize;
}


VertexPositionTexture* TexturedMesh::GetVerices() {
	return vertices;
}

int TexturedMesh::GetNbVertices()
{
	return nbVertices;
}

int TexturedMesh::GetVerticesSize()
{
	return nbVertices * sizeof(VertexPositionTexture);
}