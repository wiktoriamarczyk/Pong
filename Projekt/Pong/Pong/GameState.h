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

    eStateID GetStateID()const;
    eStateID GetNextStateID()const;
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