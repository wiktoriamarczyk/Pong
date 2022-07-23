#pragma once
#include "GameState.h"


class InGameState : public GameState
{
    vector<unique_ptr<GameObject>> m_AllGameObjects;

public:
    InGameState();
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
    void OnEnter()override;
    void CreateObject();
};
