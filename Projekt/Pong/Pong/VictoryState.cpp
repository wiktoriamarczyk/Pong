#include "VictoryState.h"
#include "Ball.h"


VictoryState::VictoryState(shared_ptr<Font> MyFont) : GameState(eStateID::VICTORY)
{
    m_Font = MyFont;
}


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
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);


    m_Font->DrawText(pRenderer, 8, 180, 80, "VICTORY!");

    if (Ball::GetWinner())
    {
        m_Font->DrawText(pRenderer, 4, 200, 300, "PLAYER 1 WON");
    }
    else
    {
        m_Font->DrawText(pRenderer, 4, 200, 300, "PLAYER 2 WON");
    }

    m_Font->DrawText(pRenderer, 1, 300, 450, "CLICK ESC TO RETURN TO MENU");

    SDL_RenderPresent(pRenderer);
}