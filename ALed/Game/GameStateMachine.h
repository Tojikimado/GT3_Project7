#pragma once
#include "StateMachine.h"
#include "MainScene.h"
#include "InputController.h"

class MainScene;
class GameStateMachine;

class GameState : public State
{
protected:

public:
	MainScene* m_scene;
	GameState(MainScene* scene);
	~GameState();

	void SetStateMachine(StateMachine* stateMachine) override;

	void EnterState() override;

	void UpdateState(float dt) override;

	void LeaveState() override;
};

class InGameState : public GameState
{
protected:

	float gameDuration = 300.0f;

public:

	InGameState(MainScene* scene);
	~InGameState();

	void SetStateMachine(StateMachine* stateMachine) override;

	void EnterState() override;

	void UpdateState(float dt) override;

	void LeaveState() override;
};

class MainMenuState : public GameState
{
private : 

protected:

public:

	MainMenuState(MainScene* scene);
	~MainMenuState();

	void SetStateMachine(StateMachine* stateMachine) override;

	void EnterState() override;

	void UpdateState(float dt) override;

	void LeaveState() override;
};

class GameOverState : public GameState
{
private:

protected:

public:

	GameOverState(MainScene* scene);
	~GameOverState();

	void SetStateMachine(StateMachine* stateMachine) override;

	void EnterState() override;

	void UpdateState(float dt) override;

	void LeaveState() override;
};

class GameStateMachine : public StateMachine
{

protected:

public :

	GameStateMachine(GameState* state);
	~GameStateMachine() override;

	void Update(float dt) override;

	void SwitchState(State* nextState) override;

};

