#pragma once
#include "GameState.h"


class MainMenuState : public GameState
{
public:
    MainMenuState() : GameState(eStateID::MAINMENU) {};
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};