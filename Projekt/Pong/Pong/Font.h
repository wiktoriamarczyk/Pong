#pragma once
#include "Common.h"


// struktura gromadzaca informacje o jednym symbolu
struct CharacterData
{
    vector<string> m_ImageData;
    char m_Character;
};


// klasa gromadzaca informacje o wszystkich symbolach
class Font
{
    vector<CharacterData> m_Dictionary;

public:
    void LoadFont (const string& FileName);
    const CharacterData* FindCharacter (char Character)const;
    void DrawText (SDL_Renderer* Renderer, int PixelSize, int PosX, int PosY, const char* Text);
};


bool ReadLine(fstream& FileStream, string& OutString, int ExpectedSize);
bool LoadSingleCharacter(fstream& FileStream, CharacterData& DataOut);
vector<CharacterData> FillFontVector(const string& FileName);
void DrawLine(SDL_Renderer* pRenderer, int PixelSize, int PosX, int PosY, const string& Pixels);
void DrawLines(SDL_Renderer* pRenderer, int PixelSize, int PosX, int PosY, const vector<string>& Lines);
string ToString(int value);