#pragma once
#include "GameObject.h"
#include "vec2.h"
#include "Paddle.h"
#include "Font.h"


class Ball : public GameObject
{
    vec2 m_BallCenterPos;                           ///< polozenie pilki w przestrzeni 2D 
    vec2 m_BallSize;                                ///< wymiary pilki
    vec2 m_BallDirection;                           ///< kierunek pilki
    float m_BallSpeed = 0.0;                        ///< szybkosc przemieszczania sie pilki

    shared_ptr<Paddle> m_LeftPaddle;                ///< wskaznik na lewa paletke
    shared_ptr<Paddle> m_RightPaddle;               ///< wskaznik na prawa paletke 
    static int m_Points1;                           ///< ilosc punktow gracza pierwszego
    static int m_Points2;                           ///< ilosc punktow gracza drugiego
    shared_ptr<Font> m_Font;                        ///< wskaznik na czcionke 

public: 
    Ball(shared_ptr<Paddle> PaddleL, shared_ptr<Paddle> PaddleR, int& PointsPlOne, int& PointsPlTwo, shared_ptr<Font> MyFont);
    /** funkcja dopowiedzialna za zainicjalizowanie pilki w przestrzeni 2D
    @param BallCenterPositionX polozenie pilki wzgledem OX
    @param BallCenterPositionX polozenie pilki wzgledem OY */
    void InitializeBall (int BallCenterPositionX, int BallCenterPositionY);
    /** funkcja odpowiedzialna za update logiki pilki
    @param DeltaTime czas trwania klatki */
    void Update (float DeltaTime)override;
    /** funkcja odpowiedzialna za renderowanie pilki na ekranie 
    @param pRenderer wskaznik na renderer */
    void Render (SDL_Renderer* pRenderer)override;
    /** statyczna funkcja informujaca o tym, ze ktorys z graczy osiagnal odpowiednia liczbe punktow 
    @return true, jesli ktorys z graczy osiagnal wynik determinujacy o jego zwyciestwie */
    static bool Victory();
    /** statyczna funkcja informujaca o tym, ktory gracz osiagnal zwyciestwo
    @return true, jesli zwyciezca jest gracz 1, false jesli gracz 2 */
    static bool GetWinner();
};

