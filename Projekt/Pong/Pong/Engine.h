#pragma once
#include "Common.h"
#include "GameState.h"

class Engine
{
    GameState* m_pCurrentState = nullptr;  
    vector<unique_ptr<GameState>> m_AllStates;

public:
    Engine();
    void ChangeState (eStateID StateID);
    void Loop();

};

