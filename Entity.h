#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float GetX();
    float GetY();
    SDL_Texture* GetTex();
    SDL_Rect GetCurrentFrame();
private:
    float x, y;
    SDL_Rect CurrentFrame;
    SDL_Texture* tex;
};

#endif // ENTITY_H
