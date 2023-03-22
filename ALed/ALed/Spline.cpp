#include "Spline.h"

Spline::Spline()
{
    _splinePoints = nullptr;
    _nbPoints = 0;
}

Spline::Spline(SplinePoint* splinePoints, int nbPoints) : _splinePoints(splinePoints), _nbPoints(nbPoints)
{
}

Spline::~Spline()
{
}

SplinePoint* Spline::GetSplinePoints()
{
    return _splinePoints;
}

SplinePoint Spline::GetSplinePoint(int pointIndex)
{
    return _splinePoints[pointIndex];
}

int Spline::GetNbPoints()
{
    return _nbPoints;
}
