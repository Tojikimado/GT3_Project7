#include "PlayerTrack.h"
PlayerTrack::PlayerTrack()
{
}

PlayerTrack::PlayerTrack(Camera* camera, Spline** sBuf, int nbtracks)
{
	pCamera = camera;
	currentTrack = 0;
	nbTracks = nbtracks;
	trackBuffer = new Track* [nbTracks];
	for (int i = 0; i < nbTracks; i++) {
		if(i == 0) trackBuffer[i] = new Track(pCamera->GetTransform(), sBuf[i], pCamera, false);
		else {
			D3DXVECTOR3 oldPos = trackBuffer[i-1]->GetTransform().m_position + trackBuffer[i-1]->GetSpline()->GetLastPoint().transform.m_position;
			trackBuffer[i] = new Track(Transform(oldPos, D3DXVECTOR3(0,0,0), D3DXVECTOR3(1,1,1)), sBuf[i], pCamera, false);
		}
	}
	trackBuffer[0]->ResetTrack();
	trackBuffer[0]->StartFollow();
}

PlayerTrack::~PlayerTrack()
{
}

void PlayerTrack::Update(float dt)
{
	trackBuffer[currentTrack]->Update(dt);
	if (trackBuffer[currentTrack]->GetState() == false) {
		if (currentTrack + 1 < nbTracks) {
			currentTrack++;
			//trackBuffer[currentTrack]->GetTransform().SetPosition(oldPos);
			trackBuffer[currentTrack]->ResetTrack();
			trackBuffer[currentTrack]->StartFollow();
		}
	}
}
