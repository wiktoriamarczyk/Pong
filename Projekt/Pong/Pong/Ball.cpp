#include "Ball.h"


Ball::Ball(shared_ptr<Paddle> PaddleL, shared_ptr<Paddle> PaddleR, int& PointsPlOne, int& PointsPlTwo)
{
    m_LeftPaddle = PaddleL;
    m_RightPaddle = PaddleR;
    m_Points1 = PointsPlOne;
    m_Points2 = PointsPlTwo;
}


void Ball::InitializeBall (int BallCenterPositionX, int BallCenterPositionY)
{
    m_BallCenterPos.x = float(BallCenterPositionX);
    m_BallCenterPos.y = float(BallCenterPositionY);

    m_BallSpeed = float(BALL_SPEED);
    m_BallSize.x = float(BALL_SIZE);
    m_BallSize.y = float(BALL_SIZE);

    // kierunek wektora musi byc znormalizowany, wiec go obliczamy i przypisujemy do kierunku pilki 
    vec2 Direction(1, 1);
    m_BallDirection = Direction.GetNormalized();
}


void Ball::Render (SDL_Renderer* pRenderer)
{
    vec2 BallTopLeftCorner = m_BallCenterPos - m_BallSize / 2;

    // tworzymy pilke jako kwadrat
    SDL_Rect BallDrawRect;
    BallDrawRect.x = (int)BallTopLeftCorner.x;
    BallDrawRect.y = (int)BallTopLeftCorner.y;
    BallDrawRect.w = (int)m_BallSize.x;
    BallDrawRect.h = (int)m_BallSize.y;

    // ustawiamy kolor pilki na bialy
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    // rysujemy pilke
    SDL_RenderFillRect(pRenderer, &BallDrawRect);
}

void Ball::Update (float DeltaTime)
{
    // m_BallSpeed -> pixels / second, ale kazda klatka nie bierze jednej sekundy, bierze 'DeltaTime' sekund (1/60 sekundy)
   // by obliczyc przebyty dystans pilki w tej klatce nalezy pomnozyc jej predkosc przez dlugosc trwania klatki
    float FrameDistance = m_BallSpeed * DeltaTime; 

    // FrameDistance to dystans przebyty na plaszczyznie jednowymiarowej, jednak nasza pilka porusza sie w kierunku m_BallDirection,
    // dlatego by otrzymac zmiane pozycji w 2D, nalezy pomnozyc ten kierunek przez dystans w danej klatce
    vec2 FrameDistanceIn2D = m_BallDirection * FrameDistance;

    // by otrzymac nowa pozycje, nalezy dodac do starej pozycji dystans przebyty w 2D
    vec2 NewCenterPosition = m_BallCenterPos + FrameDistanceIn2D;
    // ta nowa pozycja staje sie nasza aktualna pozycja
    m_BallCenterPos = NewCenterPosition;

    // jesli pilka dotknie sufitu, odbije sie od niego (zmieniajac kierunek wzgledem OY na przeciwny), to samo kiedy dotknie podlogi
    if (m_BallCenterPos.y > SCREEN_HEIGHT)
    {
        m_BallDirection.y = -m_BallDirection.y;
    }

    /*if (m_BallCenterPos.y <= 0)
    {
        m_BallDirection.y = -m_BallDirection.y;
    }*/

}

