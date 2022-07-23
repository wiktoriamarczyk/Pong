#pragma once
#include "Common.h"

class GameState
{  
public:
    virtual void Update (float DeltaTime) = 0;
    virtual void Render (SDL_Renderer* pRenderer) = 0;
};

class MainMenuState : public GameState
{
public:
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};

class InGameState : public GameState
{
public:
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};

class SettingsState : public GameState
{
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};

class VictoryState : public GameState
{
public:
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);
};