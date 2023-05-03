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
    CurrentFrame.h = 100;

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

void render(Entity& p_entity, SDL_Renderer* renderer)
{
    SDL_Rect src;
    src.x = p_entity.GetCurrentFrame().x;
    src.y = p_entity.GetCurrentFrame().y;
    src.w = p_entity.GetCurrentFrame().w;
    src.h = p_entity.GetCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.GetX();
    dst.y = p_entity.GetY();
    dst.w = p_entity.GetCurrentFrame().w;
    dst.h = p_entity.GetCurrentFrame().h;
    cerr << p_entity.type ;
    cerr << p_entity.GetX() << " " << p_entity.GetY() << endl;

    SDL_RenderCopy(renderer, p_entity.GetTex(), &src, &dst);
}

