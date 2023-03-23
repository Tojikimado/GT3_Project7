#include "GenerateRandPlayerSplines.h"

GenerateRandPlayerSplines::GenerateRandPlayerSplines(int trackLength)
{
	_trackLength = trackLength;
	_splineBuffer = new Spline* [trackLength];
	int splineIndex;
	for (int i = 0; i < _trackLength; i++) {
		splineIndex = rand() % 7;
		switch (splineIndex) {
		case 0:
			_splineBuffer[i] = PlayerSplines::StraightSpline(10).spline;
			break;
		case 1:
			_splineBuffer[i] = PlayerSplines::StraightSpinSpline(10).spline;
			break;
		case 2:
			_splineBuffer[i] = PlayerSplines::RightStrafSpline(10).spline;
			break;
		case 3:
			_splineBuffer[i] = PlayerSplines::LeftStrafSpline(10).spline;
			break;
		case 4:
			_splineBuffer[i] = PlayerSplines::LeftStrafSpline(10).spline;
			break;
		case 5:
			_splineBuffer[i] = PlayerSplines::LeftStrafSpline(10).spline;
			break;
		case 6:
			_splineBuffer[i] = PlayerSplines::LeftStrafSpline(10).spline;
			break;
		default:
			_splineBuffer[i] = PlayerSplines::StraightSpline(10).spline;
		}
	}
}

GenerateRandPlayerSplines::~GenerateRandPlayerSplines()
{
}
