
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;
class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float GetX();
    float GetY();
    SDL_Texture* GetTex();
    SDL_Rect GetCurrentFrame();
    string type = "Entity";

private:
    float x, y;
    SDL_Rect CurrentFrame;
    SDL_Texture* tex;
};
void render(Entity& p_entity, SDL_Renderer* renderer);


#endif // ENTITY_H
