#include "Common.h"
#include "GameState.h"
#include "Engine.h"


int InitScreen (GameState& state);
void GameLoop (SDL_Renderer* pRenderer, GameState& state);

int main()
{
    InGameState state;

    // inicjalizacja okna
    InitScreen(state);


    // posprzatanie zasobow

    return 0;
}

void GameLoop(SDL_Renderer* pRenderer, GameState& state)
{
    // dla kazdej klatki bedziemy:
    // 1) sprawdzac wszystkie 'eventy' wyslane przez system operacyjny -> nas interesuje tylko event zamykajacy aplikacje
    // 2) Update logiki gry
    // 3) Render gry
    // 4) czekanie 1/60 sekundy na kolejna klatke

    while (true)
    {
        SDL_Event EVENT = {};

        while (SDL_PollEvent (&EVENT))
        {
            if (EVENT.type == SDL_QUIT)
                return;
        }
        state.Render( pRenderer);
        SDL_Delay (1000 / 60);
    }
}

int InitScreen(GameState& state)
{
    // zainicjalizowanie biblioteki SDL
    // uzycie flagi video oraz audio
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    //                czestotliwosc, format, kanaly, 
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        return 1;
    }

    // utworzenie okna naszej gry
    SDL_Window* pWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // sprawdzenie, czy okno zostalo utworzone
    if (pWindow == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    // utworzenie renderera, by moc rysowac rzeczy na ekranie
    //                            przypisanie do okienka, indeks karty graficznej '-1' -> pierwsza jaka znajdzie w systemie
    SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == nullptr)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    GameLoop (pRenderer, state);
}