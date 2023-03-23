#pragma once
#include "Track.h"
#include "Camera.h"
class PlayerTrack
{
public:
	PlayerTrack();
	PlayerTrack(Camera* camera, Spline** sBuf, int nbtracks);
	~PlayerTrack();

	void Update(float dt);
private:
	Camera* pCamera;

	int currentTrack;
	int nbTracks;
	Track** trackBuffer;

};
