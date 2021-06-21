#include "Ball.h"


int Ball:: m_Points1 = 0;
int Ball::m_Points2 = 0;


Ball::Ball(shared_ptr<Paddle> PaddleL, shared_ptr<Paddle> PaddleR, int& PointsPlOne, int& PointsPlTwo, shared_ptr<Font> MyFont)
{
    m_Font = MyFont;

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

    // wyswietlamy punktacje na ekranie
    m_Font->DrawText(pRenderer, 5, 200, 20, ToString(m_Points1).c_str());
    m_Font->DrawText(pRenderer, 5, 550, 20, ToString(m_Points2).c_str());
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


    // ----------KOLIZJA Z PODLOGA I SUFITEM (GORNA I DOLNA KRAWEDZIA OKIENKA)----------

    // jesli pilka dotknie podlogi, odbije sie od niej (zmieniajac kierunek wzgledem OY na przeciwny)
    if (m_BallCenterPos.y > SCREEN_HEIGHT)
    {
        m_BallDirection.y = -m_BallDirection.y;
    }
    // to samo sie stanie, kiedy dotknie sufitu
    if (m_BallCenterPos.y <= 0)
    {
        m_BallDirection.y = -m_BallDirection.y;
    }

    // ----------KOLIZJA Z PALETKAMI----------

    // kolizja z prawa paletka
    // jesli pilka znajduje sie w obszarze wystepowania prawej paletki, sprawdz za  pomoca funkcji CrossedPaddle czy doszlo do kolizji
    if (m_BallCenterPos.x >= (SCREEN_WIDTH - 5))
    {
        if (m_RightPaddle->CrossedPaddle(m_BallCenterPos))
        {
            // jesli doszlo do kolizji, niech zachowa swoja predkosc oraz odbije sie od paletki (zminiajac swoj kierunek wzgledem OX) 
            m_BallSpeed = BALL_SPEED;
            m_BallDirection.x = -m_BallDirection.x;
        }
        // w innym wypadku prawa paletka pilki nie odbila, zatem pilka wypada poza ekran 
        // niech tworzy sie na nowo na srodku ekranu lecac w losowym kierunku w strone gracza przeciwnego z nieco zmniejszona predkoscia na samym poczatku
        // gracz pierwszy zyskuje punkt
        else
        {
            m_BallSpeed = BALL_SPEED - 150;
            m_BallCenterPos.x = SCREEN_WIDTH / 2;
            m_BallCenterPos.y = SCREEN_HEIGHT / 2;
            srand(time(NULL));
            vec2 Direction((rand() % 5) - 5, (rand() % 5) - 5);
            m_BallDirection = Direction.GetNormalized();
            m_Points1++;
        }
    }

    // kolizja z lewa paletka -> analogicznie
    if (m_BallCenterPos.x <= 5)
    {
        if (m_LeftPaddle->CrossedPaddle(m_BallCenterPos))
        {
            m_BallSpeed = BALL_SPEED;
            m_BallDirection.x = -m_BallDirection.x;
        }
        else
        {
            m_BallSpeed = BALL_SPEED - 150;
            m_BallCenterPos.x = SCREEN_WIDTH / 2;
            m_BallCenterPos.y = SCREEN_HEIGHT / 2;
            srand(time(NULL));
            vec2 Direction((rand() % 5) + 1, (rand() % 5) + 1);
            m_BallDirection = Direction.GetNormalized();
            m_Points2++;
        }
    }
}


bool Ball::Victory()
{
    if (m_Points1 >= 1 || m_Points2 >= 1)
    {
        return true;
    }
    return false;
}


bool Ball::GetWinner()
{
    if (m_Points1 >= 1)
    {
        return true;
    }
    else return false;
}
