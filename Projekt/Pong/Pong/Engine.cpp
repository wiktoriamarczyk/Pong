#include "Engine.h"
#include "InGameState.h"
#include "MainMenuState.h"
#include "SettingsState.h"
#include "VictoryState.h"


Engine::Engine()
{
    m_AllStates.push_back (make_unique<InGameState>());
    m_AllStates.push_back (make_unique<MainMenuState>());
    m_AllStates.push_back(make_unique<SettingsState>());
    m_AllStates.push_back(make_unique<VictoryState>());

    ChangeState (eStateID::MAINMENU);
}

void Engine::ChangeState (eStateID StateID)
{
    for (int i = 0; i < m_AllStates.size(); ++i)
    {
        if (m_AllStates[i]->GetStateID() == StateID)
        {
            m_pCurrentState = m_AllStates[i].get();
            m_pCurrentState->OnEnter();
            return;
        }
    }
}

bool Engine::Initialize()
{
    // zainicjalizowanie okna gry oraz dzwieku
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    //                czestotliwosc, format, kanaly, 
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        return false;
    }

    // utworzenie okna naszej gry
    pWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // sprawdzenie, czy okno zostalo utworzone
    if (pWindow == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    // utworzenie renderera, by moc rysowac rzeczy na ekranie
    //                            przypisanie do okienka, indeks karty graficznej '-1' -> pierwsza jaka znajdzie w systemie
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == nullptr)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    //Paddle LeftPaddle;
    //LeftPaddle.InitializePaddle(5, SCREEN_HEIGHT/2, SDL_SCANCODE_W, SDL_SCANCODE_S);

    return true;
}

void Engine::Loop()
{

    // ----------GLOWNA PETLA GRY----------
    // dla kazdej klatki bedziemy:
    // 1) sprawdzac 'eventy' wysylane przez system operacyjny (zamkniecie aplikacji przez uzytkownika)
    // 2) update logiki gry
    // 3) renderowanie gry
    // 4) czekanie 1/60 sekundy na nastepmna klatke

    while (true)
    {
        // oczekiwanie na 'event' -> nas interesuje tylko ewentualne wyjscie z aplikacji
        SDL_Event EVENT = {};

        while (SDL_PollEvent(&EVENT))
        {
            if (EVENT.type == SDL_QUIT)
                return;
        }

        // odswiezanie 60 klatek na sekunde (SDL_Delay w milisekundach)
        SDL_Delay(1000 / 60);

        // renderowanie naszej gry oraz update'owanie jej logiki
        m_pCurrentState->Update(1.0f / 60.0f);
        m_pCurrentState->Render(pRenderer);

        // domyslnie nastepny stan jest UNKNOWN, gdy nie chcemy przechodzic do nowego stanu, zatem jesli jest tam cos innego, tzn. ze bylo zazadanie zmiany stanu
        if (m_pCurrentState->GetNextStateID() != eStateID::UNKNOWN)
        {
            ChangeState(m_pCurrentState->GetNextStateID());
        }
    }
}
