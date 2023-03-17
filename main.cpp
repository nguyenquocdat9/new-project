#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Entity.h"

using namespace std;



void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, Entity& Ship);

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Texture* background = loadTexture("background.jpg", renderer);
    SDL_Texture* obstacle = loadTexture("meteor.png", renderer);
    SDL_Texture* spaceship = loadTexture("spaceship.png", renderer);
    int Xship = SCREEN_WIDTH / 2, Yship = SCREEN_HEIGHT / 2;
    int step = 6;


    bool GameIsRunning = true;
    SDL_Event e;


    while(GameIsRunning)
    {
        Entity Ship(Xship, Yship, spaceship);
        // Đợi 10 mili giây
        SDL_Delay(10);
        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
          if ( SDL_WaitEvent(&e) == 0) continue;
        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
          if (e.type == SDL_QUIT) break;
        // Nếu có một phím được nhấn, thì xét phím đó là gì để xử lý tiếp
          if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break; // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        		// Nếu phím mũi tên trái, dịch sang trái
    	        // (cộng chiều rộng, trừ bước, rồi lấy phần dư để giá trị luôn dương, và hiệu ứng quay vòng)
        		case SDLK_LEFT: Xship = (Xship + SCREEN_WIDTH - step) % SCREEN_WIDTH;
        			break;
        		// Tương tự với dịch phải, xuống và lên
            	case SDLK_RIGHT: Xship = (Xship + step) % SCREEN_WIDTH;
            		break;
            	case SDLK_DOWN: Yship = (Yship + step) % SCREEN_HEIGHT;
					break;
            	case SDLK_UP: Yship = (Yship + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
            		break;
        		default: break;
			}
        }
        refreshScreen(window, renderer, Ship);
    }
    return 0;
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

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, Entity& Ship)
{
    SDL_RenderClear(renderer);

    SDL_Texture* background = loadTexture("background.jpg", renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    // ve background

    render(Ship, renderer);
    // ve vat the con tau

    SDL_RenderPresent(renderer);
    // hien thi man hinh
}
