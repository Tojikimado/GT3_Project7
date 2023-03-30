#include "PTrack.h"

PTrack::PTrack()
{
}

PTrack::PTrack(Camera* camera)
{
	pCamera = camera;
	currentTrack = 0;
	pTrack = new Track(pCamera->GetTransform(), PlayerSplines::StraightSpline(10).spline, pCamera, false);
	pTrack->ResetTrack();
	pTrack->StartFollow();
}

PTrack::~PTrack()
{
	if (pTrack != nullptr) delete pTrack;
}

void PTrack::Update(float dt)
{
	pTrack->Update(dt);
	if (pTrack->GetState() == false) {
		GenerateTrack(RandomSpline());
		pTrack->ResetTrack();
		pTrack->StartFollow();
	}
}

void PTrack::GenerateTrack(Spline* spline)
{
	D3DXVECTOR3 oldPos = pTrack->GetTransform().m_position + pTrack->GetSpline()->GetLastPoint().transform.m_position;
	pTrack = new Track(Transform(oldPos, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1)), spline, pCamera, false);
}

Spline* PTrack::RandomSpline()
{
	int splineIndex = rand() % 8;
	switch (splineIndex) {
	case 0:
		return PlayerSplines::StraightSpline(10).spline;
		break;
	case 1:
		return PlayerSplines::StraightSpinSpline(10).spline;
		break;
	case 2:
		return PlayerSplines::RightStrafSpline(10).spline;
		break;
	case 3:
		return PlayerSplines::LeftStrafSpline(10).spline;
		break;
	case 4:
		return PlayerSplines::LoopingSpline(10).spline;
		break;
	case 5:
		return PlayerSplines::StraightSpline(10).spline;
		break;
	case 6:
		return PlayerSplines::StraightSpline(10).spline;
		break;
	case 7:
		return PlayerSplines::StraightSpline(10).spline;
		break;
	default:
		return PlayerSplines::StraightSpline(10).spline;
	}
}