#pragma once
#include "Common.h"


/** struktura gromadzaca informacje o jednym symbolu wczytanym z pliku */
struct CharacterData
{
    vector<string> m_ImageData;
    char m_Character;
};


/** klasa gromadzaca informacje o wszystkich symbolach */
class Font
{
    vector<CharacterData> m_Dictionary;                 ///< wektor wszystkich symboli 

public:
    /** funkcja odpowiedzialna za zaladowanie czcionki 
    @param FileName nazwa pliku, z ktorego odczytujemy czcionke */
    void LoadFont (const string& FileName);
    /** funkcja zwracajaca symbol
    @param Character szukany symbol */
    const CharacterData* FindCharacter (char Character)const;
    /** funkcja odpowiedzialna za rysowanie czcionki na ekranie 
    @param Renderer wskaznik na renderer
    @param PixelSize wielkosc jednego piksela symbolu
    @param PosX pozycja tekstu wzgledem OX
    @param PosY pozycja tekstu wzgledem OY 
    @param Text ciag znakow jaki ma zostac narysowany na ekranie */
    void DrawText (SDL_Renderer* Renderer, int PixelSize, int PosX, int PosY, const char* Text);
};

// FUNKCJE POMOCNICZE

/** funkcja odpowiedzialna za przeczytanie jednej linii ciagu znakow z pliku
@param FileStream plik, z ktorego odczytujemy dane
@param OutString jedna linia przeczytanych znakow
@param ExpectedSize oczekiwana ilosc znakow do przeczytania
@return true jesli dlugosc ciagu znakow jest rowna oczekiwanemu rozmiarowi, false jesli dlugosc jest inna */
bool ReadLine(fstream& FileStream, string& OutString, int ExpectedSize);

/** funkcja wczytujaca caly symbol (cyfre lub litere)
@param FileStream plik, z ktorego odczytujemy dane
@param DataOut obiekt klasy CharacterData do ktorego wczytujemy informacje o symbolu 
@return true jesli symbol wczytano poprawnie */
bool LoadSingleCharacter(fstream& FileStream, CharacterData& DataOut);

/** funkcja odpowiedzialna za stworzenie slownika
@param FileName nazwa pliku, z ktorego odczytujemy dane
@return wektor obiektow typu CharacterData */
vector<CharacterData> FillFontVector(const string& FileName);

/** funkcja odpowiedzialna za narysowanie jednej linii symbolu 
@param pRenderer wskaznik na renderer
@param PosX pozycja tekstu wzgledem OX
@param PosY pozycja tekstu wzgledem OY
@param Pixels linia, z ktorej odczytujemy dane */
void DrawLine(SDL_Renderer* pRenderer, int PixelSize, int PosX, int PosY, const string& Pixels);

/** funkcja rysujaca caly symbol
@param pRenderer wskaznik na renderer
@param PosX pozycja tekstu wzgledem OX
@param PosY pozycja tekstu wzgledem OY
@param Lines wektor odczytanych linii symbolu */
void DrawLines(SDL_Renderer* pRenderer, int PixelSize, int PosX, int PosY, const vector<string>& Lines);

/** funkcja pomocnicza przekonwertuj¹ca int na string 
@param value typ int, ktory chcemy zwrocic w postaci stringa 
@return zwrocenie przekonwertowanego inta na stringa */
string ToString(int value);