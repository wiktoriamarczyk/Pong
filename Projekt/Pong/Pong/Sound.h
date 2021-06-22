#pragma once
#include "Common.h"


class Sound
{
    Mix_Chunk* m_pSoundData = nullptr;          ///< wskaznik na 'chunk' (dzwiek)

public:
    Sound() = default;
    ~Sound();
    /** funkcja odpowiedzialna za zaladowanie dzwieku
    @param fileName nazwa pliku z ktorego wczytujemy dzwiek 
    @return true jesli wczytywanie sie powiodlo, false jesli zakonczylo sie niepomyslnie */
    bool Load(const string& fileName);
    /** funkcja odpowiedzlana za odegranie dzwieku */
    void Play()const;
};

