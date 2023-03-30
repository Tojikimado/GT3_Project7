#include "StateMachine.h"


//finite state machine 
StateMachine::StateMachine(State* state)
{	
	this->SwitchState(state);
}

StateMachine::~StateMachine()
{
}

void StateMachine::Update(float dt)
{
	m_currentState->UpdateState(dt);
}

void StateMachine::SwitchState(State* nextState)
{
	if (m_currentState != nullptr)
	{
		m_currentState->LeaveState();
		delete m_currentState;
	}

	m_currentState = nextState;
	nextState->SetStateMachine(this);
	nextState->EnterState();
}

//states
State::State()
{
}

State::~State()
{
}

void State::SetStateMachine(StateMachine* stateMachine)
{
	m_stateMachine = stateMachine;
}

void State::EnterState()
{
}

void State::UpdateState(float dt)
{
}

void State::LeaveState()
{
}
