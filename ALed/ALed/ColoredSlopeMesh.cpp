#include "ColoredSlopeMesh.h"

ColoredSlopeMesh::ColoredSlopeMesh() : ColoredSlopeMesh(1.f, 1.f, 1.f, D3DCOLOR_XRGB(255, 0, 255), true, true)
{
}

ColoredSlopeMesh::ColoredSlopeMesh(float width, float height, float deepth, D3DCOLOR color, bool vOrientation = true, bool hOrientation = true)
{
	// Settup Orientation
	width = (hOrientation * 2 - 1) * width;
	height = (vOrientation * 2 - 1) * height;

	// Create a Cube by default
	VertexPositionColor* slopeVertices = new VertexPositionColor[6];
	slopeVertices[0] = { -1.0f * width, -1.0f * height, -1.0f * deepth, color, };
	slopeVertices[1] = { -1.0f * width, 1.0f * height, -1.0f * deepth, color, };
	slopeVertices[2] = { 1.0f * width, -1.0f * height, -1.0f * deepth, color, };
	slopeVertices[3] = { 1.0f * width, -1.0f * height, 1.0f * deepth, color, };
	slopeVertices[4] = { -1.0f * width, 1.0f * height, 1.0f * deepth, color, };
	slopeVertices[5] = { -1.0f * width, -1.0f * height, 1.0f * deepth, color, };

	vertices = slopeVertices;
	nbVertices = 6;

	// create the indices using an int array
	short* baseIndices = new short[24];
	baseIndices[0] = 0; baseIndices[1] = 1; baseIndices[2] = 2;   // side 1

	baseIndices[3] = 2; baseIndices[4] = 1; baseIndices[5] = 4;    // side 2
	baseIndices[6] = 2; baseIndices[7] = 4; baseIndices[8] = 3;

	baseIndices[9] = 5; baseIndices[10] = 4; baseIndices[11] = 1;    // side 3
	baseIndices[12] = 5; baseIndices[13] = 1; baseIndices[14] = 0;

	baseIndices[15] = 0; baseIndices[16] = 2; baseIndices[17] = 3;    // side 4
	baseIndices[18] = 0; baseIndices[19] = 3; baseIndices[20] = 5;

	baseIndices[21] = 3; baseIndices[22] = 4; baseIndices[23] = 5;    // side 5

	indices = baseIndices;
	nbIndices = 24;
}

ColoredSlopeMesh::ColoredSlopeMesh(float width, float height, float deepth) : ColoredSlopeMesh(width, height, deepth, D3DCOLOR_XRGB(255, 0, 255))
{
}
