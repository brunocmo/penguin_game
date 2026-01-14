#pragma once

#include <SDL2/SDL.h>
#include <string>

#include <State.hpp>

class Game
{
public:
    Game(std::string title, int width, int height);
    ~Game();

    void Run();
    SDL_Renderer * GetRenderer();
    State& GetState();
    static Game& GetInstance();

private:

    static Game * instance;
    SDL_Window* window;
    SDL_Renderer * renderer;
    State * state;
};

