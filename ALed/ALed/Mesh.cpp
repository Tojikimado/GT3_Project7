#include "Mesh.h"

short* Mesh::GetIndices()
{
	return indices;
}
int Mesh::GetNbIndices()
{
	return nbIndices;
}

int Mesh::GetIndicesSize()
{
	return nbIndices*sizeof(short);
}
