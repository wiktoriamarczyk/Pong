#pragma once
#include "GameState.h"


class VictoryState : public GameState
{
    shared_ptr<Font> m_Font;

public:
    VictoryState (shared_ptr<Font> MyFont);
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};