#include "ColoredRectangleMesh.h"

ColoredRectangleMesh::ColoredRectangleMesh() : ColoredMesh()
{
}

ColoredRectangleMesh::ColoredRectangleMesh(float width, float height, float deepth, D3DCOLOR color)
{
	// Create a Cube by default
	VertexPositionColor* rectVertices = new VertexPositionColor[8];
	rectVertices[0] = { -1.0f * width, 1.0f * height, -1.0f * deepth, color, };
	rectVertices[1] = { 1.0f * width, 1.0f * height, -1.0f * deepth, color, };
	rectVertices[2] = { -1.0f * width, -1.0f * height, -1.0f * deepth, color, };
	rectVertices[3] = { 1.0f * width, -1.0f * height, -1.0f * deepth, color, };
	rectVertices[4] = { -1.0f * width, 1.0f * height, 1.0f * deepth, color, };
	rectVertices[5] = { 1.0f * width, 1.0f * height, 1.0f * deepth, color, };
	rectVertices[6] = { -1.0f * width, -1.0f * height, 1.0f * deepth, color, };
	rectVertices[7] = { 1.0f * width, -1.0f * height, 1.0f * deepth, color, };

	this->vertices = rectVertices;
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

ColoredRectangleMesh::ColoredRectangleMesh(float width, float height, float deepth): ColoredRectangleMesh(width, height, deepth, D3DCOLOR_XRGB(255, 0, 255))
{
}
