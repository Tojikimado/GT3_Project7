#include "TexturedMesh.h"

TexturedMesh::TexturedMesh() : TexturedMesh("wall.png")
{
}

TexturedMesh::TexturedMesh(const char* texFile) {
	// Create a Cube by default
	VertexPositionTexture* cubeVertices = new VertexPositionTexture[24];
	// Front face
	cubeVertices[0] = { -1.0f, 1.0f, -1.0f, 0.f, 0.f, }; // A
	cubeVertices[1] = { 1.0f, 1.0f, -1.0f,  1.f, 0.f, }; // B
	cubeVertices[2] = { -1.0f, -1.0f, -1.0f,  0.f, 1.f, }; // C
	cubeVertices[3] = { 1.0f, -1.0f, -1.0f, 1.f, 1.f, }; // D
	// Back face
	cubeVertices[4] = { 1.0f, 1.0f, 1.0f, 0.f, 0.f, }; // E
	cubeVertices[5] = { -1.0f, 1.0f, 1.0f, 1.f, 0.f, }; // F
	cubeVertices[6] = { 1.0f, -1.0f, 1.0f, 0.f, 1.f, }; // G
	cubeVertices[7] = { -1.0f, -1.0f, 1.0f, 1.f, 1.f, }; // H
	// Left face
	cubeVertices[8] = { -1.0f, 1.0f, 1.0f, 0.f, 0.f, }; // F
	cubeVertices[9] = { -1.0f, 1.0f, -1.0f, 1.f, 0.f, }; // A
	cubeVertices[10] = { -1.0f, -1.0f, 1.0f, 0.f, 1.f, }; // H
	cubeVertices[11] = { -1.0f, -1.0f, -1.0f, 1.f, 1.f, }; // C
	// Right face
	cubeVertices[12] = { 1.0f, 1.0f, -1.0f, 0.f, 0.f, }; // B
	cubeVertices[13] = { 1.0f, 1.0f, 1.0f, 1.f, 0.f, }; // E
	cubeVertices[14] = { 1.0f, -1.0f, -1.0f, 0.f, 1.f, }; // D
	cubeVertices[15] = { 1.0f, -1.0f, 1.0f, 1.f, 1.f, }; // G
	// Top face
	cubeVertices[16] = { -1.0f, 1.0f, 1.0f, 0.f, 0.f, }; // F
	cubeVertices[17] = { 1.0f, 1.0f, 1.0f, 1.f, 0.f, }; // E
	cubeVertices[18] = { -1.0f, 1.0f, -1.0f, 0.f, 1.f, }; // A
	cubeVertices[19] = { 1.0f, 1.0f, -1.0f, 1.f, 1.f, }; // B
	// Bottom face
	cubeVertices[20] = { 1.0f, -1.0f, 1.0f, 0.f, 0.f, }; // G
	cubeVertices[21] = { -1.0f, -1.0f, 1.0f, 1.f, 0.f, }; // H
	cubeVertices[22] = { -1.0f, -1.0f, -1.0f, 1.f, 1.f, }; // C
	cubeVertices[23] = { 1.0f, -1.0f, -1.0f, 0.f, 1.f, }; // D

	this->vertices = cubeVertices;
	this->nbVertices = 24;

	// create the indices using an int array
	short* baseIndices = new short[36];
	baseIndices[0] = 0; baseIndices[1] = 1; baseIndices[2] = 2;   // Front face
	baseIndices[3] = 2; baseIndices[4] = 1; baseIndices[5] = 3;

	baseIndices[6] = 4; baseIndices[7] = 5; baseIndices[8] = 6;    // Back face
	baseIndices[9] = 6; baseIndices[10] = 5; baseIndices[11] = 7;

	baseIndices[12] = 8; baseIndices[13] = 9; baseIndices[14] = 10;    // Left Face
	baseIndices[15] = 10; baseIndices[16] = 9; baseIndices[17] = 11;

	baseIndices[18] = 12; baseIndices[19] = 13; baseIndices[20] = 14;    // Right Face
	baseIndices[21] = 14; baseIndices[22] = 13; baseIndices[23] = 15;

	baseIndices[24] = 16; baseIndices[25] = 17; baseIndices[26] = 18;    // Top Face
	baseIndices[27] = 18; baseIndices[28] = 17; baseIndices[29] = 19;

	baseIndices[30] = 20; baseIndices[31] = 21; baseIndices[32] = 22;    // Bottom Face
	baseIndices[33] = 22; baseIndices[34] = 23; baseIndices[35] = 20;

	this->indices = baseIndices;
	this->nbIndices = 36;

	this->texFileName = texFile;
}

TexturedMesh::TexturedMesh(VertexPositionTexture* newvertices, int size, short* indices, int indiceSize, const char* texFile)
{
	this->vertices = newvertices;
	this->nbVertices = size;
	this->indices = indices;
	this->nbIndices = indiceSize;
	this->texFileName = texFile;
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

const char* TexturedMesh::GetTexFileName()
{
	return texFileName;
}
