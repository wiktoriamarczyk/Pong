#pragma once
#include<iostream>
#include<SDL_Mixer.h>
#include<SDL.h>
#ifdef main
// erase SDL2 #define of 'main' keyword
#undef main
#endif


enum : int
{
    SCREEN_WIDTH = 800,
    SCREEN_HEIGHT = 600,

    BALL_SIZE = 10,
    BALL_SPEED = 600,

    PADDLE_WIDTH = 10,
    PADDLE_HEIGHT = 100,
    PADDLE_SPEED = 400,

};