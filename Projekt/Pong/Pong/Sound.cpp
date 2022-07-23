#include "Sound.h"


Sound::~Sound()
{
    Mix_FreeChunk(m_pSoundData);
}


bool Sound::Load(const string& fileName)
{
    m_pSoundData = Mix_LoadWAV(("../Data/" + fileName).c_str());

    return m_pSoundData == nullptr ? false : true;
}


void Sound::Play()const
{
    Mix_PlayChannel(-1, m_pSoundData, 0);
}

