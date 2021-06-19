#pragma once
#include "GameState.h"
#include "Font.h"


class SettingsState : public GameState
{
public:
    SettingsState(shared_ptr<Font> MyFont);
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};
