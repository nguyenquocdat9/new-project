#include <iostream>
#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Entity.h"

using namespace std;

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, Entity& Ship, Entity& asteroid, SDL_Texture* background);

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);

int main(int argc, char* argv[])
{

    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Texture* background = loadTexture("D:/code/snake/image/background.jpg", renderer);
    SDL_Texture* obstacle = loadTexture("D:/code/snake/image/meteor.png", renderer);
    SDL_Texture* spaceship = loadTexture("D:/code/snake/image/spaceship.png", renderer);
    // generate value
    int Xship = SCREEN_WIDTH / 2, Yship = SCREEN_HEIGHT / 2;
    int step = 5;
    bool GameIsRunning = true;
    SDL_Event e;

    srand((unsigned int) time(NULL));
    int x = 0;
    int y = (rand() % 696) + 1;



    while(GameIsRunning)
    {
        Entity *asteroid = new Entity(x, y, obstacle);
        asteroid->type = "asteroid";
        // check if asteroid is rendered
        Entity Ship(Xship, Yship, spaceship);
        Ship.type = "ship";
        // Đợi 10 mili giây
        SDL_Delay(3);

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
          while( SDL_PollEvent(&e) != 0 ){
        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
          if (e.type == SDL_QUIT) GameIsRunning = false;
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
          }
        x += 4;
        refreshScreen(window, renderer, Ship, *asteroid, background);
        if(x >= 1500)
        {
            delete asteroid;
            x = 0;
            y = (rand() % 696) + 1;
        }


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

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, Entity& Ship, Entity& asteroid, SDL_Texture* background)
{
    SDL_RenderClear(renderer);


    SDL_RenderCopy(renderer, background, NULL, NULL);
    // ve background

    render(Ship, renderer);
    // ve vat the con tau
    render(asteroid,renderer);

    SDL_RenderPresent(renderer);
    // hien thi man hinh
}
