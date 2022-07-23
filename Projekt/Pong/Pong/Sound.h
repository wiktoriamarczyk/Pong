#pragma once
#include "Common.h"


class Sound
{
    Mix_Chunk* m_pSoundData = nullptr;
public:
    Sound() = default;
    ~Sound();
    bool Load(const string& fileName);
    void Play()const;
};

