#pragma once
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
#include "PTrack.h"
#include "TrackPosition.h"
#include "Spaceship.h"
#include "GenerateSpaceships.h"
#include "Raycast.h"
#include "Landscape.h"

#include "GameStateMachine.h"

class ExplosionParticle;
class GameStateMachine;

class MainScene : public D3DApp
{
public:

	MainScene(HINSTANCE hInstance);

	~MainScene();

	bool Init() override;
	void Update(float dt) override;
	void Render() override;

	void LoadScene();
	void UnloadScene();

	PTrack* pTrack = nullptr;
	GenerateSpaceships* sGenerator = nullptr;
	ExplosionParticle* pParticleSystem = nullptr;
	Landscape* m_landscape = nullptr;

	GameStateMachine* pStateMachine = nullptr;

protected : 

	std::vector<Spaceship*> v_spaceships;
};

