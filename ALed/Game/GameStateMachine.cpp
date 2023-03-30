#include "GameStateMachine.h"
#include "InputController.h"

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

GameState::GameState() : State()
{
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
InGameState::InGameState()
{
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

	OutputDebugStringA("enter in game \n");
}

void InGameState::UpdateState(float dt)
{
	gameDuration -= dt;
	if (gameDuration <= 0.f)
	{
		m_stateMachine->SwitchState(new GameOverState());
	}
}

void InGameState::LeaveState()
{
	GameState::LeaveState();

	OutputDebugStringA("leaving ingame \n");
}

#pragma endregion

#pragma region mainmenu
MainMenuState::MainMenuState()
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

	OutputDebugStringA("main menu \n");
}

void MainMenuState::UpdateState(float dt)
{
	if (InputController::Get()->IsKeyDown(VK_RBUTTON))
	{
		m_stateMachine->SwitchState(new InGameState());
	}
}

void MainMenuState::LeaveState()
{
	GameState::LeaveState();

	OutputDebugStringA("leaving menu \n");
}
#pragma endregion

#pragma region game over

GameOverState::GameOverState()
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
	OutputDebugStringA("enter game over \n");
}

void GameOverState::UpdateState(float dt)
{
	if (InputController::Get()->IsKeyDown(VK_RBUTTON))
	{
		m_stateMachine->SwitchState(new MainMenuState());
	}
}

void GameOverState::LeaveState()
{
	GameState::LeaveState();
	OutputDebugStringA("leaving game over \n");
}

#pragma endregion