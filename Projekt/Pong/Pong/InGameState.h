#pragma once
#include "GameState.h"


class InGameState : public GameState
{
    vector<shared_ptr<GameObject>> m_AllGameObjects;
    
public:
    InGameState(shared_ptr<Font> MyFont);
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
    void OnEnter()override;
    void CreateObject();
};
