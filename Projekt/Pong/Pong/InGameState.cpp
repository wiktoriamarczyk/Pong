#include "InGameState.h"
#include "Common.h"
#include "Paddle.h"


InGameState::InGameState() : GameState(eStateID::INGAME)
{
    CreateObject();
}


void InGameState::CreateObject()
{
    m_AllGameObjects.clear();

    unique_ptr<Paddle> LeftPaddle = make_unique<Paddle>();
    LeftPaddle->InitializePaddle(5, SCREEN_HEIGHT / 2, SDL_SCANCODE_W, SDL_SCANCODE_S);

    unique_ptr<Paddle> RightPaddle = make_unique<Paddle>();
    RightPaddle->InitializePaddle(SCREEN_WIDTH - 5, SCREEN_HEIGHT / 2, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);


    m_AllGameObjects.push_back(std::move(LeftPaddle));
    m_AllGameObjects.push_back(std::move(RightPaddle));
}


void InGameState::OnEnter()
{
    GameState::OnEnter();
    CreateObject();
}


void InGameState::Update(float DeltaTime)
{
    // nacisniecie esc gwarantuje wyjscie do 'menu'
    if (SDL_IsKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        m_NextStateID = eStateID::MAINMENU;
    }
    for (int i = 0; i < m_AllGameObjects.size(); ++i)
    {
        m_AllGameObjects[i]->Update(DeltaTime);
    }
}


void InGameState::Render(SDL_Renderer* pRenderer)
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

    for (int i = 0; i < m_AllGameObjects.size(); ++i)
    {
        m_AllGameObjects[i]->Render(pRenderer);
    }

    // wyswietlamy wszystko z aktualnej klatki
    SDL_RenderPresent(pRenderer);
}

