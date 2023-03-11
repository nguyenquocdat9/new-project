#ifndef UTILS_H_
#define UTILS_H_



#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
	int screenWidth, int screenHeight, const char* windowTitle) ;

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();



#endif // UTILS_H_
