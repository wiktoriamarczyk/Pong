#pragma once
#include "Common.h"


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
    void OnEnter();
};


class MainMenuState : public GameState
{
public:
    MainMenuState() : GameState (eStateID::MAINMENU) {};
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};


class InGameState : public GameState
{
public:
    InGameState() : GameState (eStateID::INGAME) {};
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};


class SettingsState : public GameState
{
public:
    SettingsState() : GameState (eStateID::SETTINGS) {};
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};


class VictoryState : public GameState
{
public:
    VictoryState() : GameState(eStateID::VICTORY) {};
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};