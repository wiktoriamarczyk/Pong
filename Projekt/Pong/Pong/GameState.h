#pragma once
#include "Common.h"
#include "GameObject.h"


class Engine;


class GameState
{  
    const eStateID m_StateID = eStateID::UNKNOWN;

protected:
    eStateID m_NextStateID = eStateID::UNKNOWN;

public:
    GameState (eStateID StateID);
    
    virtual void Update (float DeltaTime)=0;
    virtual void Render (SDL_Renderer* pRenderer)=0;

    // funkcja zwracajaca ID aktualnego stanu gry
    eStateID GetStateID()const;
    // funkcja zwracajaca ID kolejnego stanu, na ktory chcemy przejsc z aktualnego
    eStateID GetNextStateID()const;
    // funkcja ustawiajaca na starcie aktualny stan jako ten nastepny, by uniknac zapetlajacego sie przeskakiwania miedzy stanami
    virtual void OnEnter();
};