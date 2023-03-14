#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Entity.h"

using namespace std;





SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    int x = 100, y = 200;
    SDL_Texture* background = loadTexture("background.jpg", renderer);
    SDL_Texture* obstacle = loadTexture("meteor.png", renderer);
    SDL_Texture* spaceship = loadTexture("spaceship.png", renderer);
    Entity Ship(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, spaceship);
    bool GameIsRunning = true;
    SDL_Event e;

    while(GameIsRunning)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                GameIsRunning = false;
            }
        }
        Entity meteor(x, y, obstacle);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        render(meteor, renderer);
        render(Ship, renderer);
        SDL_RenderPresent(renderer);
        x++;
    }
}

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer)
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if(loadedSurface == nullptr)
        cout << "Unable to load image" << path << "SDL_image Error: " << SDL_GetError() << endl;
    else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(newTexture == nullptr)
            cout << "Unable to create texture from " << path << " SDL Error: " << SDL_GetError() << endl;
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}
