#pragma once
#include "Track.h"
class TrackPosition : public Track
{
public:
	TrackPosition();
	TrackPosition(Spline* spline, GameObject* splineFollower, bool looping);
	TrackPosition(Transform transform, Spline* spline, GameObject* splineFollower, bool looping);
	~TrackPosition();

	void Update(float dt);
	void UpdateTransform();
};

