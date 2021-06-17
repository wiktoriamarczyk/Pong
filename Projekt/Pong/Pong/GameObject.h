#pragma once
#include "Common.h"


class GameObject
{
public:
    virtual void Update (float DeltaTime) = 0;
    virtual void Render (SDL_Renderer* pRenderer) = 0;
};
