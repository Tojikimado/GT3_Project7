#include "GameStateMachine.h"

GameStateMachine::GameStateMachine(GameState* state) : StateMachine(state)
{
}

GameStateMachine::~GameStateMachine()
{
	StateMachine::~StateMachine();
}

void GameStateMachine::Update(float dt)
{
	StateMachine::Update(dt);
}

void GameStateMachine::SwitchState(State* nextState)
{
	StateMachine::SwitchState(nextState);
}

GameState::GameState(MainScene* scene) : State()
{
	m_scene = scene;
}

GameState::~GameState()
{
	State::~State();
}

void GameState::SetStateMachine(StateMachine* stateMachine)
{
	State::SetStateMachine(stateMachine);
}

void GameState::EnterState()
{
	State::EnterState();
}

void GameState::UpdateState(float dt)
{
	State::UpdateState(dt);
}

void GameState::LeaveState()
{
	State::LeaveState();
}


#pragma region ingame
InGameState::InGameState(MainScene* scene) : GameState(scene)
{
	m_scene->SetMaxTime(gameDuration);
}

InGameState::~InGameState()
{
}

void InGameState::SetStateMachine(StateMachine* stateMachine)
{
	GameState::SetStateMachine(stateMachine);
}

void InGameState::EnterState()
{
	GameState::EnterState();
	m_scene->LoadScene();
	OutputDebugStringA("enter in game \n");
}

void InGameState::UpdateState(float dt)
{
	gameDuration -= dt;
	if (gameDuration <= 0.f)
	{
		m_stateMachine->SwitchState(new GameOverState(m_scene));
	}

	if (InputController::Get()->IsKeyDown(Input::DXK_ESCAPE))
	{
		m_stateMachine->SwitchState(new GameOverState(m_scene));
	}
}

void InGameState::LeaveState()
{
	GameState::LeaveState();
	m_scene->UnloadScene();
	OutputDebugStringA("leaving ingame \n");
}

#pragma endregion

#pragma region mainmenu
MainMenuState::MainMenuState(MainScene* scene) : GameState(scene)
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::SetStateMachine(StateMachine* stateMachine)
{
	GameState::SetStateMachine(stateMachine);
}

void MainMenuState::EnterState()
{
	GameState::EnterState();
	m_scene->LoadMainMenuScene();
	OutputDebugStringA("main menu \n");
}

void MainMenuState::UpdateState(float dt)
{
	if (m_scene->m_playLabel != nullptr)
	{
		if (m_scene->m_playLabel->Update(m_scene->GetHWND(), ButtonAction::PLAY) == ButtonAction::PLAY)
		{
			m_stateMachine->SwitchState(new InGameState(m_scene));
		}
		else if (m_scene->m_quitLabel != nullptr)
		{
			if (m_scene->m_quitLabel->Update(m_scene->GetHWND(), ButtonAction::QUIT) == ButtonAction::QUIT)
			{
				PostQuitMessage(0);
			}
		}
	}
	
	
}

void MainMenuState::LeaveState()
{
	GameState::LeaveState();
	m_scene->UnloadMainMenuScene();
	OutputDebugStringA("leaving menu \n");
}
#pragma endregion

#pragma region game over

GameOverState::GameOverState(MainScene* scene) : GameState(scene)
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::SetStateMachine(StateMachine* stateMachine)
{
	GameState::SetStateMachine(stateMachine);
}

void GameOverState::EnterState()
{
	GameState::EnterState();
	m_scene->LoadEndScene();
	OutputDebugStringA("enter game over \n");
}

void GameOverState::UpdateState(float dt)
{
	if (m_scene->m_mainMenuLabel != nullptr)
	{
		if (m_scene->m_mainMenuLabel->Update(m_scene->GetHWND(), ButtonAction::MENU) == ButtonAction::MENU)
		{
			m_stateMachine->SwitchState(new MainMenuState(m_scene));
		}
		else if (m_scene->m_quitLabel != nullptr)
		{
			if (m_scene->m_quitLabel->Update(m_scene->GetHWND(), ButtonAction::QUIT) == ButtonAction::QUIT)
			{
				PostQuitMessage(0);
			}
		}
	}
}

void GameOverState::LeaveState()
{
	GameState::LeaveState();
	m_scene->UnloadEndScene();
	OutputDebugStringA("leaving game over \n");
}

#pragma endregion