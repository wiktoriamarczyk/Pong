#pragma once
#include "GameState.h"

class VictoryState : public GameState
{
public:
    VictoryState() : GameState(eStateID::VICTORY) {};
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};