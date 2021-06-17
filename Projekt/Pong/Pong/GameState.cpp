#include "GameState.h"
#include "Common.h"


GameState::GameState(eStateID StateID) : m_StateID(StateID) {}


eStateID GameState::GetStateID()const
{
    return m_StateID;
}

eStateID GameState::GetNextStateID()const
{
    return m_NextStateID;
}

void GameState::OnEnter()
{
    m_NextStateID = eStateID::UNKNOWN;
}


// ----------UPDATE METHODS----------

void MainMenuState::Update (float DeltaTime)
{
    // po nacisieciu enter dostajemy sie do okna gry
    if (SDL_IsKeyPressed(SDL_SCANCODE_RETURN))
    {
        m_NextStateID = eStateID::INGAME;
    }
    // nalezy przytrzymac dolny klawisz i wcisnac enter, by dostac sie do 'ustawien'
    if (SDL_IsKeyPressed(SDL_SCANCODE_DOWN))
    {
        if (SDL_IsKeyPressed(SDL_SCANCODE_RETURN))
        {
            m_NextStateID = eStateID::SETTINGS;
        }
    }
}

void InGameState::Update(float DeltaTime)
{
    // nacisniecie esc gwarantuje wyjscie do 'menu'
    if (SDL_IsKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        m_NextStateID = eStateID::MAINMENU;
    }
}

void SettingsState::Update(float DeltaTime)
{
    // nacisniecie esc gwarantuje wyjscie do 'menu'
    if (SDL_IsKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        m_NextStateID = eStateID::MAINMENU;
    }
}


void VictoryState::Update(float DeltaTime)
{
    // nacisniecie esc gwarantuje wyjscie do 'menu'
    if (SDL_IsKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        m_NextStateID = eStateID::MAINMENU;
    }
}

// ----------RENDER METHODS----------

void MainMenuState::Render (SDL_Renderer* pRenderer)
{
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
}

void InGameState::Render (SDL_Renderer* pRenderer)
{
    // wybor koloru na czarny
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    // wypelniamy caly ekran wybranym wczesniej kolorem, (czyscimy) aby nie zostaly zadne pozostalosci z poprzedniej klatki
    SDL_RenderClear(pRenderer);

    // zmieniamy kolor na bialy
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    // i rysujemy linie oddzielajaca pola graczy, rysujac prostokaty wczesniej wybranym kolorem wzdluz wysokosci ekranu
    for (int i = 0; i < SCREEN_HEIGHT; i += 20)
    {
        SDL_Rect Rect;
        Rect.x = SCREEN_WIDTH / 2;
        Rect.y = 0 + i;
        Rect.w = 8;
        Rect.h = 10;
        SDL_RenderFillRect(pRenderer, &Rect);
    }

    // wyswietlamy wszystko z aktualnej klatki
    SDL_RenderPresent(pRenderer);
}

void SettingsState::Render(SDL_Renderer* pRenderer)
{
    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
}

void VictoryState::Render(SDL_Renderer* pRenderer)
{
    SDL_SetRenderDrawColor(pRenderer, 0, 255, 255, 255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
}