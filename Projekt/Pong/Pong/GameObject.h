#pragma once
#include "Common.h"


class GameObject
{
public:
    /** czysto wirtualna funkcja odpowiedzialna za update logiki
    @param DeltaTime czas trwania jednej klatki */
    virtual void Update (float DeltaTime) = 0;
    /** czysto wirtualna funkcja odpowiedzialna za renderowanie rzeczy na ekranie 
    @param pRenderer wskaznik na renderer */
    virtual void Render (SDL_Renderer* pRenderer) = 0;
};
