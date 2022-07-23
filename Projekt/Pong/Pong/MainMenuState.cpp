#include "MainMenuState.h"


void MainMenuState::Update(float DeltaTime)
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


void MainMenuState::Render(SDL_Renderer* pRenderer)
{
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
}