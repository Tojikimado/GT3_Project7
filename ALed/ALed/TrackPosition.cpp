#include "TrackPosition.h"

TrackPosition::TrackPosition() : Track()
{
}

TrackPosition::TrackPosition(Spline* spline, GameObject* splineFollower, bool looping = false) : Track(spline, splineFollower, looping)
{
}

TrackPosition::TrackPosition(Transform transform, Spline* spline, GameObject* splineFollower, bool looping = false) : Track(transform, spline, splineFollower, looping)
{
}

TrackPosition::~TrackPosition()
{
}

void TrackPosition::Update(float dt)
{
	if (_movementState == true) {
		_pointProgress += _speed * dt;
		if (_pointProgress >= 1) {
			_currentPoint = _currentPoint + 1;
			_pointProgress = 0;
		}
		if (_currentPoint != (_spline->GetNbPoints() - 1)) {
			UpdateTransform();
		}
		else if (_looping) {
			ResetTrack();
		}
		else {
			_movementState = false;
			_splineFollower->GetTransform().SetPosition(_spline->GetSplinePoint(_currentPoint).transform.m_position);
		}
	}
}

void TrackPosition::UpdateTransform()
{
	Transform newTransform = m_transform;

	Transform prevTransform = _spline->GetSplinePoint(_currentPoint).transform;
	Transform nextTransform = _spline->GetSplinePoint(_currentPoint + 1).transform;

	D3DXVECTOR3 newPosition = m_transform.m_position + lerpVector3(prevTransform.m_position, nextTransform.m_position, _pointProgress);

	newTransform.SetPosition(newPosition);

	_splineFollower->SetTransform(newTransform);
}
