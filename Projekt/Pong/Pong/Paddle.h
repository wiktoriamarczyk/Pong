#pragma once
#include "GameObject.h"
#include "vec2.h"


class Paddle : public GameObject
{
    vec2 m_PaddleCenterPos;
    vec2 m_PaddleSize;
    float m_PaddleSpeed = 0;
    SDL_Scancode m_KeyToUp = SDL_SCANCODE_UNKNOWN;
    SDL_Scancode m_KeyToDown = SDL_SCANCODE_UNKNOWN;

public:
    void InitializePaddle(int PaddleCenterPositionX, int PaddleCenterPositionY, SDL_Scancode KeyToMoveUp, SDL_Scancode KeyToMoveDown);
    void Update(float DeltaTime);
    void Render(SDL_Renderer* pRenderer);

    vec2 ReturnPos()const;
};

