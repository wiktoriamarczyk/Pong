#pragma once
#include "Common.h"
#include "GameState.h"


class Engine
{
    SDL_Renderer* pRenderer = nullptr;
    SDL_Window* pWindow = nullptr;
    GameState* m_pCurrentState = nullptr;  
    vector<unique_ptr<GameState>> m_AllStates;

public:
    Engine();
    // funkcja odpowiadajaca za zmiane stanu (m_pCurrentState ma wskazywac teraz na jakis inny stan)
    void ChangeState (eStateID StateID);
    // glowna petla gry, renderowanie gry i update jej logiki co klatke
    void Loop();
    // funkcja odpowiadajaca za zainicjalizowanie okienka gry oraz dzwieku
    bool Initialize();
};


