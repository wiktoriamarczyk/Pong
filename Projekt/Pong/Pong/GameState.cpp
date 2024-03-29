#include "GameState.h"
#include "Paddle.h"


GameState::GameState(eStateID StateID) : m_StateID(StateID) {}


eStateID GameState::GetStateID()const
{
    return m_StateID;
}

eStateID GameState::GetNextStateID()const
{
    return m_NextStateID;
}

void GameState::OnEnter()
{
    m_NextStateID = eStateID::UNKNOWN;
}