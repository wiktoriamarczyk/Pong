#pragma once
#include "GameObject.h"
#include "vec2.h"


class Paddle : public GameObject
{
    vec2 m_PaddleCenterPos;                                     ///< pozycja paletki na przestrzeni 2D
    vec2 m_PaddleSize;                                          ///< rozmiar paletki
    float m_PaddleSpeed = 0.0;                                  ///< predkosc poruszania paletka
    SDL_Scancode m_KeyToUp = SDL_SCANCODE_UNKNOWN;              ///< przypisanie klawisza odpowiadajacy za poruszanie paletka do gory
    SDL_Scancode m_KeyToDown = SDL_SCANCODE_UNKNOWN;            ///< przypisanie klawisza odpowiadajacego za poruszanie paletka w dol

public:
    /** funkcja odpowiadajaca za inicjalizacje paletki 
    @param PaddleCenterPositionX inicjalizacja pozycji na ekranie wzgledem OX
    @param PaddleCenterPositionY inicjalizacja pozycji na ekranie wzgledem OY
    @param KeyToMoveUp przypisanie klawisza odpowiadajacego za poruszanie w gore
    @param KeyToMoveDown przypisanie klawisza odpowiadajacego za poruszanie w dol */
    void InitializePaddle(int PaddleCenterPositionX, int PaddleCenterPositionY, SDL_Scancode KeyToMoveUp, SDL_Scancode KeyToMoveDown);
    void Update(float DeltaTime)override;
    void Render(SDL_Renderer* pRenderer)override;

    /** funkcja odpowiedzialna za zwrocenie pozycji paletki 
    @return pozycja paletki na ekranie */
    vec2 ReturnPos()const;

    /** funkcja odpowiedzialna za zwrocenie informacji, czy polozenie pilki pokrywa sie z polozeniem paletki 
    @param BallPos polozenie pilki na ekranie
    @return true jesli polozenie pilki pokrywa sie z polozeniem paletki, false jesli nie */
    bool CrossedPaddle(vec2 BallPos);
};

