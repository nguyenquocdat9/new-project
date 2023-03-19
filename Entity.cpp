#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
{
    x = p_x;
    y = p_y;
    tex = p_tex;
    CurrentFrame.x = 0;
    CurrentFrame.y = 0;
    CurrentFrame.w = 100;
    CurrentFrame.h = 104;

}
float Entity::GetX()
{
    return x;
}
float Entity::GetY()
{
    return y;
}
SDL_Texture* Entity::GetTex()
{
    return tex;
}
SDL_Rect Entity::GetCurrentFrame()
{
    return CurrentFrame;
}

