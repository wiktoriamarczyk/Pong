#pragma once
#include "GameState.h"
#include "Font.h"


class MainMenuState : public GameState
{
public:
    MainMenuState(shared_ptr<Font> MyFont);
    void Update(float DeltaTime)override;
    void Render(SDL_Renderer* pRenderer)override;
};