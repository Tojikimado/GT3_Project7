#pragma once
#include "Spline.h"
#include "GameObject.h"
class Track : public GameObject
{
private:
	GameObject* _splineFollower;
	Spline* _spline;
	int _currentPoint = 0;
	float _pointProgress = 0;
	float _speed = 1.f;
	bool _movementState = false;
	bool _looping = false;
public:
	Track();
	Track(Spline* spline, GameObject* splineFollower, bool looping);
	Track(Transform transform, Spline* spline, GameObject* splineFollower, bool looping);

	void StartFollow();
	void PauseFollow();
	void ResetTrack();

	void Update(float dt);
	void UpdateTransform();

	D3DXVECTOR3 lerpVector3(D3DXVECTOR3 prev, D3DXVECTOR3 next, float t);

};

