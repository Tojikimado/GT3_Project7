#include "Track.h"
#include <cmath>
#include <iostream>

Track::Track()
{
	m_transform = Transform();
	_splineFollower = nullptr;
	_spline = nullptr;
}

Track::Track(Spline* spline, GameObject* splineFollower, bool looping = false)
{
	m_transform = Transform();
	_splineFollower = splineFollower;
	_spline = spline;
	_looping = looping;
}

Track::Track(Transform transform, Spline* spline, GameObject* splineFollower, bool looping = false)
{
	m_transform = transform;
	_splineFollower = splineFollower;
	_spline = spline;
	_looping = looping;
}

Track::~Track()
{
}

void Track::StartFollow()
{
	_movementState = true;
	UpdateTransform();
}

void Track::PauseFollow()
{
	_movementState = false;
}

void Track::ResetTrack()
{
	_currentPoint = 0;
	_pointProgress = 0;
}

void Track::Update(float dt)
{
	if (_movementState == true) {
		_pointProgress += _speed * dt;
		if (_pointProgress >= 1) {
			_currentPoint = _currentPoint+ 1;
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
			_splineFollower->GetTransform().SetPosition(m_transform.m_position + _spline->GetSplinePoint(_currentPoint).transform.m_position);
			//_splineFollower->GetTransform().SetRotation(m_transform.GetRotation() + _spline->GetSplinePoint(_currentPoint).transform.GetRotation());
		}
	}
}

void Track::UpdateTransform()
{
	Transform newTransform = m_transform;

	Transform prevTransform = _spline->GetSplinePoint(_currentPoint).transform;
	Transform nextTransform = _spline->GetSplinePoint(_currentPoint+1).transform;

	D3DXVECTOR3 newPosition = m_transform.m_position + lerpVector3(prevTransform.m_position, nextTransform.m_position, _pointProgress);
	/*D3DXVECTOR3 newRotation = m_transform.GetRotation() + lerpVector3(prevTransform.GetRotation(), nextTransform.GetRotation(), _pointProgress);*/
	
	newTransform.SetPosition(newPosition);
	/*newTransform.SetRotation(newRotation);*/

	_splineFollower->SetTransform(newTransform);
}

D3DXVECTOR3 Track::lerpVector3(D3DXVECTOR3 prev, D3DXVECTOR3 next, float t)
{
	D3DXVECTOR3 lerpVector3 = D3DXVECTOR3(0,0,0);
	lerpVector3.x = (prev.x + t * (next.x - prev.x));
	lerpVector3.y = (prev.y + t * (next.y - prev.y));
	lerpVector3.z = (prev.z + t * (next.z - prev.z));

	return lerpVector3;
}
