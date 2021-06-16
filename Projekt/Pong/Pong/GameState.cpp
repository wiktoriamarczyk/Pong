#include "GameState.h"
#include "Common.h"


GameState::GameState(eStateID StateID) : m_StateID(StateID) {}


eStateID GameState::GetStateID()const
{
    return m_StateID;
}


// ----------UPDATE METHODS----------

void MainMenuState::Update (float DeltaTime)
{

}

void InGameState::Update(float DeltaTime)
{

}

// ----------RENDER METHODS----------

void MainMenuState::Render (SDL_Renderer* pRenderer)
{
    SDL_SetRenderDrawColor(pRenderer, 0, 255, 255, 255);
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