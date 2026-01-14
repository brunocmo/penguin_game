#include <State.hpp>

#include <SDL2/SDL_events.h>

State::State()
{
    this->quitRequested = false;

    this->bg = new Sprite("assets/img/ocean.jpg");
    this->music = new Music("assets/audio/stageState.ogg");
}

bool State::QuitRequested()
{
    return this->quitRequested;
}

// This guy is needed to load all kinds of stuff like, music, fonts, images...
void State::LoadAssets()
{
}

void State::Update(float dt)
{
    if (SDL_QuitRequested()) this->quitRequested = true;
}

void State::Render()
{
    this->bg->Render(1024,600);
}

