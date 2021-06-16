#include "Engine.h"

Engine::Engine()
{
    m_AllStates.push_back (make_unique<InGameState>());
    m_AllStates.push_back (make_unique<MainMenuState>());

    ChangeState (eStateID::MAINMENU);
}


void Engine::ChangeState (eStateID StateID)
{
    for (int i = 0; i < m_AllStates.size(); ++i)
    {
        if (m_AllStates[i]->GetStateID() == StateID)
        {
            m_pCurrentState = m_AllStates[i].get();
            return;
        }
    }
}


void Engine::Loop()
{
    // zainicjalizowanie okna gry oraz dzwieku
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    //                czestotliwosc, format, kanaly, 
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        return;
    }

    // utworzenie okna naszej gry
    SDL_Window* pWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // sprawdzenie, czy okno zostalo utworzone
    if (pWindow == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    // utworzenie renderera, by moc rysowac rzeczy na ekranie
    //                            przypisanie do okienka, indeks karty graficznej '-1' -> pierwsza jaka znajdzie w systemie
    SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == nullptr)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }


    char Choice = 0;


    while (true)
    {
        // oczekiwanie na 'event' -> nas interesuje tylko ewentualne wyjscie z aplikacji
        SDL_Event EVENT = {};

        while (SDL_PollEvent(&EVENT))
        {
            if (EVENT.type == SDL_QUIT)
                return;
        }

        // odswiezanie 60 klatek na sekunde 
        SDL_Delay(1000 / 60);

        // warunki przejsc miedzy stanami 
        if (m_pCurrentState->GetStateID() == eStateID::MAINMENU)
        {
            m_pCurrentState->Render(pRenderer);
            cout << "A - Game, B - quit" << endl;
            cin >> Choice;
            if (Choice == 'A')
            {
                ChangeState(eStateID::INGAME);
            }
            else if (Choice == 'B')
                return;
            if (m_pCurrentState->GetStateID() == eStateID::INGAME)
            {
                m_pCurrentState->Render(pRenderer);
                cin >> Choice;
                if (Choice == 'A')
                {
                    ChangeState(eStateID::MAINMENU);
                }
                else if (Choice == 'B')
                {
                    return;
                }
            }
        }
    }
}
