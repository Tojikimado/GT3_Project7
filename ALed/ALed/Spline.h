#pragma once
#include "Transform.h"

struct SplinePoint { Transform transform; };

class Spline
{
private:
	SplinePoint* _splinePoints;
	int _nbPoints;
public:
	Spline();
	Spline(SplinePoint* splinePoints, int nbPoints);
	~Spline();
	SplinePoint* GetSplinePoints();
	SplinePoint GetSplinePoint(int pointIndex);
	SplinePoint GetLastPoint();
	int GetNbPoints();

};

