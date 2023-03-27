#pragma once
#include <Camera.h>
#include <Spline.h>
#include <Track.h>
#include "SplinePresets.h"
class PTrack
{
public:
	PTrack();
	PTrack(Camera* camera);
	~PTrack();

	void Update(float dt);

	void GenerateTrack(Spline* spline);

private:
	Camera* pCamera;

	Spline* RandomSpline();

	int currentTrack;
	Track* pTrack;
};

