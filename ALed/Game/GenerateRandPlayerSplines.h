#pragma once
#include "PTrack.h"
#include <stdlib.h>
#include "SplinePresets.h"

class GenerateRandPlayerSplines
{
public:
	Spline** _splineBuffer;
	int _trackLength;

	GenerateRandPlayerSplines(int trackLength);
	~GenerateRandPlayerSplines();
};

