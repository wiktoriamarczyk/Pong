#include "MainMenuState.h"
#include "Engine.h"


MainMenuState::MainMenuState(shared_ptr<Font> MyFont) : GameState(eStateID::MAINMENU)
{
    m_Font = MyFont;
}


void MainMenuState::Update(float DeltaTime)
{
    // jesli gracz wciska esc, wywolaj zamkniecie programu
    if (SDL_IsKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        Engine::GetSingleton()->ExitGame();
    }

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
    // ustawiamy kolor ekranu na czarny
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);

    m_Font->DrawText(pRenderer, 10, 250, 80, "PONG");
    m_Font->DrawText(pRenderer, 1, 300, 200, "CLICK ENTER TO CHOOSE");
    m_Font->DrawText(pRenderer, 5, 180, 250, "->NEW GAME");
    m_Font->DrawText(pRenderer, 5, 180, 300, "->SETTINGS");
    m_Font->DrawText(pRenderer, 5, 180, 350, "->EXIT");
    m_Font->DrawText(pRenderer, 1, 300, 450, "AUTHOR: WIKTORIA MARCZYK");

    // wyswietl wszystko na ekranie
    SDL_RenderPresent(pRenderer);
}