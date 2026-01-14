#include <Sprite.hpp>

#include <iostream>

#include <Game.hpp>
#include <SDL2/SDL_image.h>

 Sprite::Sprite()
{
    texture = nullptr;
}

Sprite::Sprite(std::string file)
{
    texture = nullptr;
    this->Open(file);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(this->texture);
}

void Sprite::Open(std::string file)
{
    if (this->texture != nullptr) SDL_DestroyTexture(this->texture);

    this->texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if(this->texture == nullptr)
    {
        std::cout << "Error loading texture: " << SDL_GetError() << '\n';
        return;
    }

    SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    this->clipRect = {x, y, w, h};
}

void Sprite::Render(int x, int y )
{
    SDL_Rect copyRect = {x, y, this->clipRect.w, this->clipRect.h};
    SDL_RenderCopy(
            Game::GetInstance().GetRenderer(),
            this->texture,
            &this->clipRect,
            &copyRect);
}

int Sprite::GetWidth()
{
    return this->width;
}

int Sprite::GetHeight()
{
    return this->height;
}

bool Sprite::IsOpen()
{
    if (texture != nullptr) return true;
    return false;
}

