#include "GameState.h"
#include "Common.h"

void InGameState::Update(float DeltaTime)
{

}


void InGameState::Render(SDL_Renderer* pRenderer)
{
    // wybor koloru, czyscimy ekran na czarno
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    // czyscimy ekran, by nie zostaly zadne pozostalosci z poprzedniej klatki
    SDL_RenderClear(pRenderer);

    // rysujemy linie oddzielajaca pola graczy, rysujac prostokaty wzdluz wysokosci ekranu
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