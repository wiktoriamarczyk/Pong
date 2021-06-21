#pragma once
#include "GameObject.h"
#include "vec2.h"
#include "Paddle.h"
#include "Font.h"


class Ball : public GameObject
{
    vec2 m_BallCenterPos;
    vec2 m_BallSize;
    vec2 m_BallDirection;
    float m_BallSpeed = 0.0;

    shared_ptr<Paddle> m_LeftPaddle;
    shared_ptr<Paddle> m_RightPaddle;
    static int m_Points1;
    static int m_Points2;
    shared_ptr<Font> m_Font;

public:
    Ball(shared_ptr<Paddle> PaddleL, shared_ptr<Paddle> PaddleR, int& PointsPlOne, int& PointsPlTwo, shared_ptr<Font> MyFont);

    void InitializeBall (int BallCenterPositionX, int BallCenterPositionY);
    void Update (float DeltaTime)override;
    void Render (SDL_Renderer* pRenderer)override;

    // funkcja zwracajaca true, jesli ktorys z graczy osiagnal wynik determinujacy o jego zwyciestwie
    static bool Victory();
    // funkcja zwracajaca true, jesli zwyciezca jest gracz 1, false jesli gracz 2
    static bool GetWinner();
};

