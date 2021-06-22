#pragma once
#include <cmath>


// pomocnicza klasa pozwalajaca na wykonywanie roznych operacji matematycznych na obiektach na plaszczyznie dwuwymiarowej
class vec2
{
public:
    float x = 0;                                        ///< wspolrzedna x
    float y = 0;                                        ///< wspolrzedna y

    vec2 ()=default;
    vec2 (float _x, float _y);

    /** funkcja odpowiedzialna za otrzymanie informacji o dlugosci wektora 
    @return dlugosc wektora */
    float GetLength()const;

    /** funckja odpowiedzialna za znormalizowanie wektora (by wskazywal tylko kierunek)
    @return wektor znormalizowany */
    vec2 GetNormalized()const;

    vec2 operator+(const vec2& other)const;
    vec2 operator-(const vec2& other)const;
    vec2 operator-()const;
    vec2 operator*(const vec2& other)const;
    vec2 operator*(float scalar)const;
    vec2 operator / (float scalar)const;
};

