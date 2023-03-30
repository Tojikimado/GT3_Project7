#pragma once
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include "d3dUtil.h"

class Mesh
{
protected:
	short* indices;
	int nbIndices;

public:
	Mesh();
	~Mesh();
	short* GetIndices();
	int GetNbIndices();
	int GetIndicesSize();
};

