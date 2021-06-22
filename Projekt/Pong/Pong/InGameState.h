#pragma once
#include "GameState.h"


class InGameState : public GameState
{
    vector<shared_ptr<GameObject>> m_AllGameObjects;            ///< wektor wskaznikow na wszystkie obiekty wystepujace w tym stanie
    
public:
    InGameState(shared_ptr<Font> MyFont);
    void Update(float DeltaTime)override;
    void Render(SDL_Renderer* pRenderer)override;
    void OnEnter()override;
    /** funkcja odpowiedzialna za stworzenie obiektow wystepujacych w tym stanie */
    void CreateObject();
};
