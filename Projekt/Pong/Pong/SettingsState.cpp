#include "SettingsState.h"


void SettingsState::Update(float DeltaTime)
{
    // nacisniecie esc gwarantuje wyjscie do 'menu'
    if (SDL_IsKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        m_NextStateID = eStateID::MAINMENU;
    }
}


void SettingsState::Render(SDL_Renderer* pRenderer)
{
    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
}