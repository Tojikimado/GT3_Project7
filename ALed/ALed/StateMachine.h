#pragma once
#include "d3dUtil.h"
#include <map>

class StateMachine;

class State
{
protected:

	StateMachine* m_stateMachine = nullptr;

public:

	State();
	~State();

	virtual void SetStateMachine(StateMachine* stateMachine);

	virtual void EnterState();
	virtual void UpdateState(float dt);
	virtual void LeaveState();

};


class StateMachine
{
protected:

	State* m_currentState;

public: 

	StateMachine(State* state); 
	virtual ~StateMachine();

	virtual void Update(float dt);

	virtual	void SwitchState(State* nextState);
};
