#pragma once
#include "Common.h"
#include "GameState.h"
#include "Sound.h"


class Engine
{
    static Engine* pSingleton;
    bool m_IsFullscreen = false;
    SDL_Renderer* pRenderer = nullptr;
    SDL_Window* pWindow = nullptr;
    GameState* m_pCurrentState = nullptr;  
    vector<unique_ptr<GameState>> m_AllStates;
    Sound m_wall_sound;
    Sound m_paddle_sound;
    Sound m_error_sound;
    bool m_IsSoundOn = true;

public:
    Engine();
    ~Engine();
    static Engine* GetSingleton();
    // funkcja odpowiadajaca za zmiane stanu (m_pCurrentState ma wskazywac teraz na jakis inny stan)
    void ChangeState (eStateID StateID);
    // glowna petla gry, renderowanie gry i update jej logiki co klatke
    void Loop();
    // funkcja odpowiadajaca za zainicjalizowanie okienka gry oraz dzwieku
    bool Initialize();

    void SetFullscreen(bool IsFullscreen);
    bool IsFullscreen()const;

    void PlayWallSound()const;
    void PlayPaddleSound()const;
    void PlayErrorSound()const;
    void TurnOnOffSound(bool IsSoundOn);
    bool IsSoundOn()const;
};


