#pragma once
#include "Common.h"
#include "GameObject.h"
#include "Font.h"


class Engine;


class GameState
{  
    const eStateID m_StateID = eStateID::UNKNOWN;           ///< zmienna przechowujaca informacje o typie aktualnego stanu

protected:
    eStateID m_NextStateID = eStateID::UNKNOWN;            ///< zmienna przechowujaca informacje o typie nastepnego stanu
    shared_ptr<Font> m_Font;                               ///< wskaznik na czcionke

public:
    GameState(eStateID StateID);
    
    /** czysto wirtualna funkcja odpowiedzialna za update logiki
    @param DeltaTime czas trwania jednej klatki */
    virtual void Update (float DeltaTime)=0;
    /** czysto wirtualna funkcja odpowiedzialna za renderowanie rzeczy na ekranie 
    @param pRenderer wskaznik na renderer */
    virtual void Render (SDL_Renderer* pRenderer)=0;

    /** funkcja zwracajaca ID aktualnego stanu gry */
    eStateID GetStateID()const;
    /** funkcja zwracajaca ID kolejnego stanu, na ktory chcemy przejsc z aktualnego */
    eStateID GetNextStateID()const;
    /** funkcja ustawiajaca na starcie aktualny stan jako ten nastepny, by uniknac zapetlajacego sie przeskakiwania miedzy stanami */
    virtual void OnEnter();
};