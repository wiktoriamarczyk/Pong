#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include<SDL_Mixer.h>
#include<SDL.h>

#ifdef main
// erase SDL2 #define of 'main' keyword
#undef main
#endif

using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::cout;
using std::cin;
using std::endl;


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

enum class eStateID
{
    UNKNOWN = 0,
    MAINMENU = 1,
    INGAME = 2,
    VICTORY = 3,
    SETTINGS = 4,

};
