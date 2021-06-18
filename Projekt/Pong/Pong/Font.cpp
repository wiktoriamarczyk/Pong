#include "Font.h"


// funkcja pozwalajaca na znalezienie danego symbolu w naszym slowniku
const CharacterData* Font::FindCharacter(char Character)const
{
    for (int i = 0; i < m_Dictionary.size(); ++i)
    {
        if (m_Dictionary[i].m_Character == Character)
            return &m_Dictionary[i];
    }
    return nullptr;
}

// funkcja odpowiedzialna za zaladowanie czcionki z wykorzystaniem funkcji zwracajacej slownik FillFontVector
void Font::LoadFont(const string& FileName)
{
    m_Dictionary = FillFontVector(FileName);
}

// funkcja odpowiedzialna za narysowanie danego tekstu na ekranie z wykorzystaniem funkcji pomocniczej DrawLines
// funkcja ta przechodzi po kolei po kazdym znaku z zadanego ciagu Text, uzywajac funkcji FindCharacterData, aby odszukac w slowniku obiekt klasy CharacterData
// ktory zawiera dane potrzebne do jej narysowania 
// jesli nie ma danych potrzebnych do narysowania symbolu, pomijamy te iteracje petli, jesli jest poprawny, wolamy funkcje DrawLines
void Font::DrawText(SDL_Renderer* pRenderer, int PixelSize, int PosX, int PosY, const char* Text)
{
    const int CharacterSpacing = PixelSize * 8;
    for (int i = 0; Text[i] != 0; ++i)
    {
        const CharacterData* pData = FindCharacter(Text[i]);
        if (pData == nullptr)
            continue;
        DrawLines (pRenderer, PixelSize, PosX + i*CharacterSpacing, PosY, pData->m_ImageData);
    }
}



// funkcja pomocnicza odpowiedzialna za przeczytanie jednej linii do OutString z pliku FileStream i zwrocenie true, jesli dlugosc OutString jest rowna oczekiwanemu rozmiarowi
bool ReadLine(fstream& FileStream, string& OutString, int ExpectedSize)
{
    getline(FileStream, OutString);
    if (OutString.size() == ExpectedSize)
        return true;
    return false;
}


// funkcja pomocnicza wczytujaca caly symbol (cyfre lub litere) przy wykorzystaniu funkcji wczytujacej linie z pliku ReadLine
// 1) kazdy symbol rozpoczyna sie znakiem reprezentujacym symbol
// 2) nastepnie w 7 liniach maksymalnie po 7 znakow 'X' wystepuje graficzna reprezentacja symbolu
// 3) ostatnia linia nie zawiera zadnych znakow, stanowi przerwe pomiedzy kolejnym symbolem czcionki
bool LoadSingleCharacter(fstream& FileStream, CharacterData& DataOut)
{
    string temp_char;

    // 1) sprobuj wczytac linie z pliku o dlugosci jednego znaku, jesli sie nie uda zwroc false
    if (!(ReadLine(FileStream, temp_char, 1)))
        return false;

    // do m_Character przypiszmy wczytany znak
    DataOut.m_Character = temp_char[0];

    string temp_line;

    // 2) petla dla 7 linii
    for (int i = 0; i < 7; ++i)
    {
        // sprobouj wczytac z pliku linie o dlugosci 7 znakow
        if (ReadLine(FileStream, temp_line, 7) == false)
        {
            return false;
        }
        // do m_FontData wczytajmy nasza linie
        DataOut.m_ImageData.push_back(temp_line);
    }

    // 3) sprobuj wczytac z pliku linie o dlugosci 0 znakow, jesli sie uda -> caly symbol wczytano poprawnie i zwroc true
    if (ReadLine(FileStream, temp_line, 0) == false)
    {
        return false;
    }
    return true;
}


// funkcja odpowiedzialna za stworzenie slownika, zwroci wektor obiektow typu CharacterData, czyli dane o kazdym symbolu 
// z wykorzystaniem funkcji wczytujacej caly symbol LoadSingleCharacter
vector<CharacterData> FillFontVector(const string& FileName)
{
    // wektor naszych symboli
    vector<CharacterData> Dictionary;

    // sprobuj otworzyc plik z symbolami, jesli sie nie uda, zwroc pusty wektor
    fstream file(FileName.c_str());
    if (!file)
    {
        return Dictionary;
    }

    // petla dzialajaca dopoki zostaly znaki do wczytania
    while (true)
    {
        if (file.eof())
        {
            return Dictionary;
        }

        CharacterData Data;

        // sprobuj wczytac dane o jednym symbolu do zmiennej Data, jesli sie nie udalo, zwroc pusty wektor
        if (LoadSingleCharacter(file, Data) == false)
        {
            return Dictionary;
        }
        // dodaj Data (dane o jednym symbolu) do wektora Dictionary
        Dictionary.push_back(Data);
    }
    // zwroc slownik odczytanych symboli
    return Dictionary;
}

// funkcja pomocnicza odpowiedzialna za narysowanie jednej linii symbolu, np dla literki W:
//XX   XX <- to jest jedna linia tego symbolu, narysujemy dwa biale pixele, trzy przezroczyste oraz dwa biale
//XX   XX
//XX   XX
//XX X XX
//XXXXXXX
//XXX XXX
//XX   XX
void DrawLine (SDL_Renderer* pRenderer, int PixelSize, int PosX, int PosY, const string& Pixels)
{
    for (int i = 0; i < Pixels.size(); ++i)
    {
        if (Pixels[i] != ' ')
        {
            SDL_Rect PixelRect;
            // przesuwamy sie wzgledem OX, by nie narysowac wszystkiego w jednym miejscu
            PixelRect.x = PosX + i * PixelSize;
            PixelRect.y = PosY;
            PixelRect.w = PixelSize;
            PixelRect.h = PixelSize;
            SDL_RenderFillRect(pRenderer, &PixelRect);
        }
    }
}

// funkcja pomocnicza rysujaca caly symbol, dla kazdego elementu z wektora Lines wywola funkcje DrawLine
void DrawLines (SDL_Renderer* pRenderer, int PixelSize, int PosX, int PosY, const vector<string>& Lines)
{
    for (int i = 0; i < Lines.size(); ++i)
    {
        // przesuwamy sie wzgledem OY, by nie narysowac wszystkiego w jednej linii
        DrawLine (pRenderer, PixelSize, PosX, PosY + i * PixelSize, Lines[i]);
    }
}

// pomocnicza funkcja zamieniajaca int na string i zwracajaca go
string ToString(int value)
{
    char buffer[16];
    _itoa_s(value, buffer, 10);
    /*
    char* buffer2 = buffer;
    _itoa_s(value, buffer, 16, 10);
    */
    return buffer;
}