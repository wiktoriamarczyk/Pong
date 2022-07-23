#include "SettingsState.h"
#include "Engine.h"


SettingsState::SettingsState(shared_ptr<Font> MyFont) : GameState(eStateID::SETTINGS)
{
    m_Font = MyFont;
}

void SettingsState::Update(float DeltaTime)
{
    // nacisniecie esc gwarantuje wyjscie do 'menu'
    if (SDL_IsKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        m_NextStateID = eStateID::MAINMENU;
    }
    
    if (SDL_IsKeyPressed(SDL_SCANCODE_DOWN))
    {
        if (SDL_IsKeyPressed(SDL_SCANCODE_RETURN))
        {
            SDL_Delay(100);
            if (Engine::GetSingleton()->IsSoundOn())
            {
                Engine::GetSingleton()->TurnOnOffSound(false);
            }
            else
            {
                Engine::GetSingleton()->TurnOnOffSound(true);
            }
        }
    }
    else if (SDL_IsKeyPressed(SDL_SCANCODE_RETURN))
    {
        if (Engine::GetSingleton()->IsFullscreen())
        {
            Engine::GetSingleton()->SetFullscreen(false);
        }
        else
        {
            Engine::GetSingleton()->SetFullscreen(true);
        }
    }
}


void SettingsState::Render(SDL_Renderer* pRenderer)
{
    // ustawiamy kolor ekranu na czarny
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);

    m_Font->DrawText(pRenderer, 8, 160, 80, "SETTINGS");
    m_Font->DrawText(pRenderer, 4, 100, 250, "->FULLSCREEN");

    if (Engine::GetSingleton()->IsSoundOn())
    {
        m_Font->DrawText(pRenderer, 4, 100, 300, "->TURN OFF SOUND");
    }
    else
    {
        m_Font->DrawText(pRenderer, 4, 100, 300, "->TURN ON SOUND");
    }
   
    m_Font->DrawText(pRenderer, 1, 300, 450, "CLICK ESC TO RETURN TO MENU");

    SDL_RenderPresent(pRenderer);
}