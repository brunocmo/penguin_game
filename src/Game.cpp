#include <Game.hpp>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

Game::Game(std::string title, int width, int height)
{
    if (instance != nullptr)
    {
        throw "toby goy";
    }

    instance = this;

    if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0 )
    {
        std::cout << "Error with SDL_Init: " << SDL_GetError() << '\n';
    }

    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF);

    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024);
    Mix_AllocateChannels(32);

    this->window = SDL_CreateWindow(
            title.c_str(), 
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            0);

    this->renderer = SDL_CreateRenderer(
            this->window,
            -1,
            SDL_RENDERER_ACCELERATED);

    if (this->renderer == nullptr) 
    {
        std::cout << "Error with renderer: " << SDL_GetError() << '\n';
    }

    this->state = new State();
}

Game::~Game()
{
    delete this->state;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();

    IMG_Quit();
    SDL_Quit();
}

void Game::Run()
{
    while (!this->state->QuitRequested())
    {
        this->state->Update(100);
        this->state->Render();

        SDL_RenderPresent(this->renderer);

        SDL_Delay(33);
    }
}

SDL_Renderer * Game::GetRenderer()
{
    return renderer;
}

State& Game::GetState()
{
    return *state;
}

Game& Game::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Game("Penguin", 1024, 600);
    }

    return *instance;
}

Game* Game::instance;
