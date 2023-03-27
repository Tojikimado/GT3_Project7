#pragma once
#include "D3DApp.h"
#include "D3DApp.h"
#include "Camera.h"

#include "ColoredRectangle.h"
#include "ColoredCube.h"
#include "TexturedGameObject.h"
#include "ColoredSlopeMesh.h"

#include <string>
#include <cmath>
#include <math.h>
#include <corecrt_math_defines.h>
#include "PlayerTrack.h"
#include "TrackPosition.h"
#include "Spaceship.h"
#include "Raycast.h"

class MainScene : public D3DApp
{
public:

	MainScene(HINSTANCE hInstance);

	~MainScene();

	bool Init() override;
	void Update(float dt) override;
	void Render() override;

	Camera* pCamera = nullptr;
	PlayerTrack* pTrack = nullptr;

protected : 

	std::vector<Spaceship> v_spaceships;
};

