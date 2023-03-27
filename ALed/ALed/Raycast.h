#pragma once
#include "d3dUtil.h"
#include "CollisionHandler.h"

class Raycast
{
public : 

	float distance = 500.f;
	float step = 5.f;

	void SingleRayCast(int x, int y);
};

