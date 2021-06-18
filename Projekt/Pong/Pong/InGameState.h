#pragma once
#include "GameState.h"
#include "Font.h"

class InGameState : public GameState
{
    vector<shared_ptr<GameObject>> m_AllGameObjects;
    shared_ptr<Font> m_Font;

public:
    InGameState(shared_ptr<Font> MyFont);
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
    void OnEnter()override;
    void CreateObject();
};
