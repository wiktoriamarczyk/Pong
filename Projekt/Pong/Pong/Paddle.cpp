#include "Paddle.h"


void Paddle::InitializePaddle (int PaddleCenterPositionX, int PaddleCenterPositionY, SDL_Scancode KeyToMoveUp, SDL_Scancode KeyToMoveDown)
{
    m_PaddleCenterPos.x = float (PaddleCenterPositionX);
    m_PaddleCenterPos.y = float (PaddleCenterPositionY);

    m_KeyToUp = KeyToMoveUp;
    m_KeyToDown = KeyToMoveDown;

    m_PaddleSize.x = float(PADDLE_WIDTH);
    m_PaddleSize.y = float(PADDLE_HEIGHT);
    m_PaddleSpeed = float(PADDLE_SPEED);
}


vec2 Paddle::ReturnPos()const
{
    return m_PaddleCenterPos;
}


void Paddle::Render(SDL_Renderer* pRenderer)
{
    /*
    A---+
    |   |
    | C |
    |   |
    +---B

    A - lewy gorny rog paletki          -> m_PaddleCenterPos - m_PaddleSize / 2
    C - srodek paletki                  -> m_PaddleCenterPos
    B - prawy dolny rog paletki         -> m_PaddleCenterPos + m_PaddleCenterPos / 2
    */

    vec2 PaddleTopLeftCorner = m_PaddleCenterPos - m_PaddleSize / 2;

    // stworzenie paletki (prostokata), podanie jego wymiarow -> punktu od ktorego rozpoczynamy rysowanie oraz jego dlugosc i szerokosc
    // konwertujemy na int, poniewaz SDL wymaga od nas intow
    SDL_Rect PaddleDrawRect{};
    PaddleDrawRect.x = int(PaddleTopLeftCorner.x);
    PaddleDrawRect.y = int(PaddleTopLeftCorner.y);
    PaddleDrawRect.w = int(m_PaddleSize.x);
    PaddleDrawRect.h = int(m_PaddleSize.y);

    // ustawiamy kolor paletki na bialy
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    // rysowanie paletki
    SDL_RenderFillRect(pRenderer, &PaddleDrawRect);
}


void Paddle::Update (float DeltaTime)
{
    // m_PaddleSpeed -> pixels / second, ale kazda klatka nie bierze jednej sekundy, bierze 'DeltaTime' sekund (1/60 sekundy)
    // by obliczyc przebyty dystans paletki w tej klatce nalezy pomnozyc jej predkosc przez dlugosc trwania klatki
    float FrameDistance = m_PaddleSpeed * DeltaTime;


    vec2 PaddleTopLeftCorner = m_PaddleCenterPos - m_PaddleSize / 2;
    // jesli gracz wciska klawisz strzalki w gore, paletka zostanie przesunieta do gory o FrameDistance, jesli napotka kraniec okienka, nie przesunie sie dalej
    if (SDL_IsKeyPressed (m_KeyToUp) && PaddleTopLeftCorner.y >= 0)
    {
        m_PaddleCenterPos.y -= FrameDistance;
    }

    vec2 PaddleBottomRightCorner = m_PaddleCenterPos + m_PaddleSize / 2;
    // jesli gracz wciska klawisz strzalki w dol, paletka zostanie przesunieta w dol o FrameDistance, jesli napotka kraniec okienka, nie przesunie sie dalej
    if (SDL_IsKeyPressed (m_KeyToDown) && PaddleBottomRightCorner.y < SCREEN_HEIGHT)
    {
        m_PaddleCenterPos.y += FrameDistance;
    }
}

