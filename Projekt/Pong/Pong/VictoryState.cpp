#include "VictoryState.h"


void VictoryState::Update(float DeltaTime)
{
    // nacisniecie esc gwarantuje wyjscie do 'menu'
    if (SDL_IsKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        m_NextStateID = eStateID::MAINMENU;
    }
}


void VictoryState::Render(SDL_Renderer* pRenderer)
{
    SDL_SetRenderDrawColor(pRenderer, 0, 255, 255, 255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
}