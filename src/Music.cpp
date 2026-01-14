#include <Music.hpp>

#include <iostream>


Music::Music()
{
    this->music = nullptr;
}

Music::Music(std::string file)
{
    this->Open(file);
}
    
Music::~Music()
{
    this->Stop();
    Mix_FreeMusic(this->music);
}

void Music::Play(int times)
{
    Mix_PlayMusic(this->music, times);
}

void Music::Stop(int msToStop)
{
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file)
{
    Mix_Music * loadMus{nullptr};

    loadMus = Mix_LoadMUS(file.c_str());
    if(loadMus == nullptr) std::cout << "Error loading texture: " << SDL_GetError() << '\n';
}

bool Music::IsOpen()
{
    if(this->music == nullptr) return false;
    return true;
}
