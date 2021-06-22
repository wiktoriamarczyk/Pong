#pragma once
#include "Common.h"
#include "GameState.h"
#include "Sound.h"


class Engine
{
    static Engine* pSingleton;

    SDL_Renderer* pRenderer = nullptr;                          ///< wskaznik na renderer
    SDL_Window* pWindow = nullptr;                              ///< wskaznik na okno naszej gry

    GameState* m_pCurrentState = nullptr;                       ///< wskaznik na aktualnie wyswietlany stan
    vector<unique_ptr<GameState>> m_AllStates;                  ///< wektor wskaznikow na wszystkie stany

    Sound m_wall_sound;                                         ///< obiekt klasy Sound reprezentujacy dzwiek odbicia od sciany
    Sound m_paddle_sound;                                       ///< obiekt klasy Sound reprezentujacy dzwiek odbicia od paletki
    Sound m_error_sound;                                        ///< obiekt klasy Sound reprezentujacy dzwiek stracenia punktu przez gracza

    bool m_IsSoundOn = true;                                    ///< zmienna potwierdzajaca czy dzwieki w grze sa wlaczone 
    bool m_IsRunning = true;                                    ///< zmienna przechowujaca informacje o tym, czy stan gry jest aktywny 
    bool m_IsFullscreen = false;                                ///< zmienna potwierdzajaca czy gra dziala w trybie okienkowym

public:

    Engine();
    ~Engine();

    static Engine* GetSingleton();
    /** funkcja odpowiadajaca za zmiane stanu (m_pCurrentState ma wskazywac teraz na jakis inny stan)
    @param StateID typ stanu */
    void ChangeState (eStateID StateID);
    /** glowna petla gry, renderowanie gry i update jej logiki co klatke */
    void Loop();
    /** funkcja odpowiadajaca za zainicjalizowanie okienka gry oraz dzwieku */
    bool Initialize();
    /** funkcja odpowiedzialna za wyjscie z gry */
    void ExitGame();
    /** funkcja odpowiadajaca za zmiane trybu wyswietlania 
    @param IsFullscreen informacja na jaki tryb wyswietlania ustawiamy */
    void SetFullscreen(bool IsFullscreen);
    /** funkcja potwierdzajaca czy aktualny tryb wyswietlania jest ustawiony pelen ekran
    @return true jesli tryb to pelen ekran, false jesli domyslny okienkowy */
    bool IsFullscreen()const;
    /** funkcja odpowiadajaca za odegranie dzwieku odbicia od sciany */
    void PlayWallSound()const;
    /** funkcja odpowiadajaca za odegranie dzwieku odbicia od paletki */
    void PlayPaddleSound()const;
    /** funkcja odpowiadajaca za odegranie dzwieku utraty punktu */
    void PlayErrorSound()const;
    /** funkcja odpowiedzialna za wlaczenie lub wylaczenie dzwieku 
    @param IsSoundOn informacja czy dzwiek jest aktualnie wlaczony */
    void TurnOnOffSound(bool IsSoundOn);
    /** funkcja zwracajaca czy dzwiek jest aktualnie wlaczony 
    @return true jesli dzwiek jest wlaczony, false jesli dzwiek jest wylaczony */
    bool IsSoundOn()const;
};


