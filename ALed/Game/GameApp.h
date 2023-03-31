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

#include "ScoreManager.h"

class ExplosionParticle;
class GameStateMachine;

class GameApp : public D3DApp
{
public:

	GameApp(HINSTANCE hInstance);

	~GameApp();

	bool Init() override;
	void Update(float dt) override;
	void Render() override;

	void LoadScene();
	void UnloadScene();

	void LoadMainMenuScene();
	void UnloadMainMenuScene();

	void LoadEndScene();
	void UnloadEndScene();

	inline void SetMaxTime(int time) { m_maxTime = time; };

	inline HWND GetHWND() { return m_hAppWindow; }

	PTrack* pTrack = nullptr;
	GenerateSpaceships* sGenerator = nullptr;
	ExplosionParticle* pParticleSystem = nullptr;
	Landscape* m_landscape = nullptr;

	GameStateMachine* pStateMachine = nullptr;

	Label* m_playLabel;
	Label* m_quitLabel;
	Label* m_mainMenuLabel;
	Label* m_timerLabel;
	Label* m_scoreLabel;

protected : 

	std::vector<Spaceship*> v_spaceships;
	int m_maxTime = 300;
	float m_currentTime = 0;
};

