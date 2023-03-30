#include "MainScene.h"
#include <ColoredCubeMesh.h>
#include "LandscapeGenerator.h"
#include "GenerateRandPlayerSplines.h"
#include "UI.h"

const DWORD d3dVertex::VertexPositionColor::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;
const DWORD d3dVertex::VertexPositionTexture::FVF = D3DFVF_XYZ | D3DFVF_TEX1;

MainScene::MainScene(HINSTANCE hInstance) : D3DApp(hInstance)
{
}

MainScene::~MainScene()
{
}

bool MainScene::Init()
{
	if (pCamera == nullptr)
	{
		pCamera = new Camera(GetDevice(), GetClientWidth(), GetClientHeight(), Transform(D3DXVECTOR3(0.f, 0.f, -10.0f), D3DXVECTOR3(0.f, 0.f, 0.f), D3DXVECTOR3(1.f, 1.f, 1.f)));
	}

	pStateMachine = new GameStateMachine(new MainMenuState(this));

	m_pDevice3D->SetRenderState(D3DRS_LIGHTING, false);
	m_pDevice3D->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	
	return true;
}

void MainScene::Update(float dt)
{
	this->D3DApp::Update(dt);

	//
	if (InputController::Get()->IsKeyDown(VK_LBUTTON))
	{
		for (Spaceship* spaceship : v_spaceships)
		{
			if(spaceship->b_isActive)
			{
				D3DXVECTOR3* cursorWorldOrigin = new D3DXVECTOR3();
				bool isHit = m_pRaycast->SingleRayCast(this->pCamera, m_pInputController->GetMouseX(this->GetAppWindow()), m_pInputController->GetMouseY(this->GetAppWindow()), spaceship->collider, cursorWorldOrigin);

				if(isHit)
				{
					spaceship->OnHit();
				}
			}
		}
	}

	//

	for (Track* gameObject : v_tracks) {
		gameObject->Update(dt);
	}
	if (sGenerator != nullptr) {
		Spaceship* spaceship = sGenerator->Update(dt);
		if (spaceship != nullptr) {
			v_spaceships.push_back(spaceship);
			spaceship->Init(m_pDevice3D);
			this->CreateColoredGameObject(spaceship);
		}
	}
	if (m_landscape != nullptr) {
		m_landscape->Update(pCamera);
	}

	if (pTrack != nullptr) {
		pTrack->Update(dt);
	}
	pStateMachine->Update(dt);
	pCamera->Update(dt);

	if (m_timerLabel != nullptr)
	{
		m_currentTime += dt;
		m_timerLabel->SetCaption(std::to_string(m_maxTime - (int)m_currentTime));
	}

	if (m_scoreLabel != nullptr)
	{
		m_scoreLabel->SetCaption("Score : " + std::to_string(ScoreManager::Get()->GetScore()));
	}
}

void MainScene::Render()
{
	this->D3DApp::Render();

}

void MainScene::LoadScene()
{

	if (pTrack == nullptr)
	{
		GenerateRandPlayerSplines randSplines = GenerateRandPlayerSplines(5);
		pTrack = new PTrack(pCamera);
	}

	//tApp->pParticleSystem = new ExplosionParticle(tApp->GetDevice(), Transform(), 1000, 5, 2.f, 0.5f, 20.f, 0.5f);

	UI* playerUI = new UI(pCamera);
	pCamera->SetUI(playerUI);
	CreateColoredGameObject(playerUI);

	ColoredMeshRenderer* ufo = new ColoredMeshRenderer("../ufo_2.x", "../Color.hlsl");
	sGenerator = new GenerateSpaceships(pCamera, ufo);

	LandscapeGenerator* land = new LandscapeGenerator(202, 202, 1.f);
	LandscapeGenerator* sky = new LandscapeGenerator(202, 202, 1.f);

	m_landscape = new Landscape(land, sky);
	ColoredGameObject** m_land = m_landscape->GetLand();
	ColoredGameObject** m_sky = m_landscape->GetSky();
	for (int i = 0; i < 4; i++) {
		this->CreateColoredGameObject(m_land[i]);
		this->CreateColoredGameObject(m_sky[i]);
	}

	for (ColoredGameObject* coloredGO : v_coloredGameObjects)
	{
		coloredGO->Init(m_pDevice3D);
	}

	m_currentTime = 0;

	RECT timerRect;
	SetRect(&timerRect, m_uiClientWidth / 2 - 25, 25, m_uiClientWidth / 2 + 25, 50);
	m_timerLabel = new Label(m_pDevice3D, this, "0", d3dColors::Red, DT_CENTER, timerRect, false);
	
	ScoreManager::Get()->ResetScore();

	RECT scoreRect;
	SetRect(&scoreRect, 25, 25, 100, 50);
	m_scoreLabel = new Label(m_pDevice3D, this, "Score : " + std::to_string(ScoreManager::Get()->GetScore()), d3dColors::Red, DT_CENTER, scoreRect, false);

	this->CreateLabels(m_timerLabel);
	this->CreateLabels(m_scoreLabel);
}

void MainScene::UnloadScene()
{
	if (pTrack != nullptr) {
		delete pTrack;
		pTrack = nullptr;
	}
	if (sGenerator != nullptr) {
		delete sGenerator;
		sGenerator = nullptr;
	}
	if (pParticleSystem != nullptr) delete pParticleSystem;
	if (m_landscape != nullptr) m_landscape = nullptr;
	for (ColoredGameObject* coloredGO : v_coloredGameObjects)
	{
		if (coloredGO != nullptr) coloredGO->~ColoredGameObject();
	}
	v_coloredGameObjects.clear();
	for (Spaceship* spaceship : v_spaceships)
	{
		if (spaceship != nullptr) delete spaceship;
	}
	v_spaceships.clear();

	for (Label* label : v_labels)
	{
		if (label != nullptr)  label->~Label();
	}
	v_labels.clear();
}

void MainScene::LoadMainMenuScene()
{
	RECT titleRect;
	SetRect(&titleRect, m_uiClientWidth / 2 - 100, 25, m_uiClientWidth / 2 + 100, 100);

	RECT playRect;
	SetRect(&playRect, m_uiClientWidth / 2 - 25, m_uiClientHeight / 2.5f - 25, m_uiClientWidth / 2 + 25, m_uiClientHeight / 2.5f + 25);
	m_playLabel = new Label(m_pDevice3D, this, "Play", d3dColors::Yellow, DT_CENTER, playRect, false);

	RECT quitRect;
	SetRect(&quitRect, m_uiClientWidth / 2 - 25, m_uiClientHeight / 2 - 25, m_uiClientWidth / 2 + 25, m_uiClientHeight / 2 + 25);
	m_quitLabel = new Label(m_pDevice3D, this, "Quit", d3dColors::Yellow, DT_CENTER, quitRect, false);

	this->CreateLabels(new Label(m_pDevice3D, this, "Roller Coaster V24", d3dColors::Yellow, DT_CENTER, titleRect, true));
	this->CreateLabels(m_playLabel);
	this->CreateLabels(m_quitLabel);
}

void MainScene::UnloadMainMenuScene()
{
	for (Label* label : v_labels)
	{
		if (label != nullptr)  label->~Label();
	}
	v_labels.clear();
}

void MainScene::LoadEndScene()
{
	RECT titleRect;
	SetRect(&titleRect, m_uiClientWidth / 2 - 100, 25, m_uiClientWidth / 2 + 100, 100);

	RECT playRect;
	SetRect(&playRect, m_uiClientWidth / 2 - 50, m_uiClientHeight / 2.5f - 25, m_uiClientWidth / 2 + 50, m_uiClientHeight / 2.5f + 25);
	m_mainMenuLabel = new Label(m_pDevice3D, this, "Main Menu", d3dColors::Yellow, DT_CENTER, playRect, false);

	RECT quitRect;
	SetRect(&quitRect, m_uiClientWidth / 2 - 25, m_uiClientHeight / 2 - 25, m_uiClientWidth / 2 + 25, m_uiClientHeight / 2 + 25);
	m_quitLabel = new Label(m_pDevice3D, this, "Quit", d3dColors::Yellow, DT_CENTER, quitRect, false);

	this->CreateLabels(new Label(m_pDevice3D, this, "Score : " + std::to_string(ScoreManager::Get()->GetScore()), d3dColors::Yellow, DT_CENTER, titleRect, true));
	this->CreateLabels(m_mainMenuLabel);
	this->CreateLabels(m_quitLabel);
}

void MainScene::UnloadEndScene()
{
	for (Label* label : v_labels)
	{
		if (label != nullptr)  label->~Label();
	}
	v_labels.clear();
}
