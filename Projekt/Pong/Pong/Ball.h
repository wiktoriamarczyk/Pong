#pragma once
#include "GameObject.h"
#include "vec2.h"
#include "Paddle.h"


class Ball : public GameObject
{
    vec2 m_BallCenterPos;
    vec2 m_BallSize;
    vec2 m_BallDirection;
    float m_BallSpeed = 0.0;

    shared_ptr<Paddle> m_LeftPaddle;
    shared_ptr<Paddle> m_RightPaddle;
    int m_Points1 = 0;
    int m_Points2 = 0;

public:
    Ball()=default;
    Ball(shared_ptr<Paddle> PaddleL, shared_ptr<Paddle> PaddleR, int& PointsPlOne, int& PointsPlTwo);
    void InitializeBall (int BallCenterPositionX, int BallCenterPositionY);
    void Update (float DeltaTime)override;
    void Render (SDL_Renderer* pRenderer)override;
};

