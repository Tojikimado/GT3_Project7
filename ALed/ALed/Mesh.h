#pragma once
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include "Component.h"
#include "d3dUtil.h"

class Mesh: public Component
{
protected:
	short* indices;
	int nbIndices;

public:
	short* GetIndices();
	int GetNbIndices();
	int GetIndicesSize();
};

