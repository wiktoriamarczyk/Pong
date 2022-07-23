#pragma once
#include "GameState.h"


class SettingsState : public GameState
{
public:
    SettingsState() : GameState(eStateID::SETTINGS) {};
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};
