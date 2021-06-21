#include "InGameState.h"
#include "Common.h"
#include "Paddle.h"
#include "Ball.h"


InGameState::InGameState(shared_ptr<Font> MyFont) : GameState(eStateID::INGAME)
{
    m_Font = MyFont;
    CreateObject();
}


void InGameState::CreateObject()
{
    // wyzeruj punkty i wyczysc vektor (przy wyjsciu z gry do menu i ponownym wejsciu, gra rozpocznie siê na nowo)
    int PointsPlOne = 0;
    int PointsPlTwo = 0;
    m_AllGameObjects.clear();

    // stworz wskazniki na paletki
    shared_ptr<Paddle> LeftPaddle = make_shared<Paddle>();
    LeftPaddle->InitializePaddle(5, SCREEN_HEIGHT / 2, SDL_SCANCODE_W, SDL_SCANCODE_S);

    shared_ptr<Paddle> RightPaddle = make_shared<Paddle>();
    RightPaddle->InitializePaddle(SCREEN_WIDTH - 5, SCREEN_HEIGHT / 2, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);

    // stworz wskaznik na pilke
    shared_ptr<Ball> MyBall = make_shared<Ball>(LeftPaddle, RightPaddle, PointsPlOne, PointsPlTwo, m_Font);
    MyBall->InitializeBall(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    // wrzuc wszystkie wskazniki na obiekty do wektora
    m_AllGameObjects.push_back(std::move(LeftPaddle));
    m_AllGameObjects.push_back(std::move(RightPaddle));
    m_AllGameObjects.push_back(std::move(MyBall));
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

    // wywolanie update na kazdym obiekcie znajdujacym sie w stanie InGame
    for (int i = 0; i < m_AllGameObjects.size(); ++i)
    {
        m_AllGameObjects[i]->Update(DeltaTime);
    }

    // jesli ktorys z graczy osiagnal liczbe punktow determinujaca o zwyciestwie, zmien stan na Victory
    if (Ball::Victory())
    {
        m_NextStateID = eStateID::VICTORY;
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

