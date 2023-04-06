#include <iostream>
#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <time.h>
#include "SDL_utils.h"
#include "Entity.h"
#include "GameMechanic.h"

using namespace std;

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* background, Entity& Ship, Entity& asteroid1, Entity& asteroid2, Entity& asteroid3, Entity& asteroid4
                   , Entity& Shield, bool ShieldUp);

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Texture* background = loadTexture("image/background.jpg", renderer);
    SDL_Texture* obstacle = loadTexture("image/meteor.png", renderer);
    //spaceship related
    SDL_Texture* barrier = loadTexture("image/shield.png", renderer);
    SDL_Texture* spaceship = loadTexture("image/spaceship.png", renderer);
    SDL_Texture* spaceshipShield = loadTexture("image/spaceshipwithshield.png", renderer);
    //menu
    SDL_Texture* GameOverScreen = loadTexture("image/gameover.jpg", renderer);
    //music
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_Music *Theme = NULL;
    Theme = Mix_LoadMUS("PurpleRain.mp3");
    // generate value
    //shield time
    const int DisappearTime = 9;//9sec
    //int step = 7;
    bool GameIsRunning = true;
    bool QuitGame = true;
    SDL_Event e;
    srand((unsigned int) time(NULL));
    SDL_Texture* ShipPhoto;

  while(QuitGame)
  {
    // 1, 3 spawn trai
    // 2, 4 spawn phai
    int Xship = SCREEN_WIDTH / 2, Yship = SCREEN_HEIGHT / 2;
    int x1 = -(rand() % 600) + 1;
    int y1 = (rand() % 696) + 1;
    int x2 = (rand() % 600) + 1501;
    int y2 = (rand() % 696) + 1;
    int x3 = -(rand() % 600) + 1;
    int y3 = (rand() % 696) + 1;
    int x4 = (rand() % 600) + 1501;
    int y4 = (rand() % 696) + 1;
    //music
    Mix_PlayMusic(Theme, 30);
    //shield
    int xShield = (rand() % 1400) + 1;
    int yShield = (rand() % 696) + 1;
    clock_t StartTime = clock();

    while(GameIsRunning)
    {
        int start = SDL_GetTicks();
        // check if asteroid is rendered
        Entity *asteroid1 = new Entity(x1, y1, obstacle);
        asteroid1->type = "asteroid1";
        Entity *asteroid2 = new Entity(x2, y2, obstacle);
        asteroid2->type = "asteroid2";
        Entity *asteroid3 = new Entity(x3, y3, obstacle);
        asteroid3->type = "asteroid3";
        Entity *asteroid4 = new Entity(x4, y4, obstacle);
        asteroid4->type = "asteroid4";
        //check render spaceship
        ShipPhoto = spaceship;
        Entity Ship(Xship, Yship, ShipPhoto);
        Ship.type = "ship";
        //shield related
        Entity *Shield = new Entity(xShield, yShield, barrier);
        Shield->type = "Shield";
        int TimeSpawn = (rand() % 10) + 20;

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
          while( SDL_PollEvent(&e) != 0 ){
        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
          if (e.type == SDL_QUIT) GameIsRunning = false;
        // Nếu có một phím được nhấn, thì xét phím đó là gì để xử lý tiếp
          /*if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break; // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        		// Nếu phím mũi tên trái, dịch sang trái
    	        // (cộng chiều rộng, trừ bước, rồi lấy phần dư để giá trị luôn dương, và hiệu ứng quay vòng)
        		case SDLK_LEFT:
        		    Xship = (Xship + SCREEN_WIDTH - step) % SCREEN_WIDTH;
        			break;
        		// Tương tự với dịch phải, xuống và lên
            	case SDLK_RIGHT:
            	    Xship = (Xship + step) % SCREEN_WIDTH;
            		break;
            	case SDLK_DOWN: Yship = (Yship + step) % SCREEN_HEIGHT;
					break;
            	case SDLK_UP: Yship = (Yship + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
            		break;
        		default: break;
			}
           }*/
           // incase want to return to keyboard control
          if(e.type == SDL_MOUSEMOTION)
          {
              SDL_GetMouseState(&Xship, &Yship);
          }
        }
        x1 += 8;
        x2 -= 8;
        x3 += 8;
        x4 -= 8;
        //shield
        clock_t ElapsedTime = clock() - StartTime;
        refreshScreen(window, renderer, background, Ship, *asteroid1, *asteroid2, *asteroid3, *asteroid4, *Shield, ShieldSpawn(ElapsedTime, TimeSpawn));
        delete asteroid1;
        delete asteroid2;
        delete asteroid3;
        delete asteroid4;
        delete Shield;
        if(x1 >= 1500)
        {
            x1 = -(rand() % 600) + 1;;
            y1 = (rand() % 696) + 1;
        }
        if(x2 <= 0)
        {
            x2 = (rand() % 600) + 1501;
            y2 = (rand() % 696) + 1;
        }
        if(x3 >= 1500)
        {
            x3 = -(rand() % 600) + 1;;
            y3 = (rand() % 696) + 1;
        }
        if(x4 <= 0)
        {
            x4 = (rand() % 600) + 1501;
            y4 = (rand() % 696) + 1;
        }
        if(CheckCollision(Xship, Yship, x1, y1))
        {
            GameIsRunning = false;
            cout << "collided" << endl;
        }
        if(CheckCollision(Xship, Yship, x2, y2))
        {
            GameIsRunning = false;
            cout << "collided" << endl;
        }
        if(CheckCollision(Xship, Yship, x3, y3))
        {
            GameIsRunning = false;
            cout << "collided" << endl;
        }
        if(CheckCollision(Xship, Yship, x4, y4))
        {
            GameIsRunning = false;
            cout << "collided" << endl;
        }

        //FPS stabilizer
        int delta = SDL_GetTicks() - start;
        if(delta < DELTA) SDL_Delay(DELTA - delta);
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, GameOverScreen, NULL, NULL);
    SDL_RenderPresent(renderer);
    while(SDL_PollEvent(&e) != 0)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
        {
           if(e.button.x >= 140 && e.button.x <= 430 && e.button.y >= 615 && e.button.y <= 735) GameIsRunning = true; // play again
           else if(e.button.x >= 1030 && e.button.x <= 1285 && e.button.y >= 615 && e.button.y <= 735) QuitGame = false; // quit game
        }
    }
  }
    // button NO 1030 -> 1290 ; 615 -> 750
    // button YES 140 -> 435 ; 615 -> 750
    quitSDL(window, renderer);
    return 0;
}

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* background, Entity& Ship, Entity& asteroid1, Entity& asteroid2, Entity& asteroid3, Entity& asteroid4
                    , Entity& Shield, bool ShieldUp)
{
    SDL_RenderClear(renderer);


    SDL_RenderCopy(renderer, background, NULL, NULL);
    // ve background

    if(ShieldUp) render(Shield, renderer);
    // ve shield

    render(Ship, renderer);
    // ve vat the con tau
    render(asteroid1,renderer);
    render(asteroid2,renderer);
    render(asteroid3,renderer);
    render(asteroid4,renderer);
    SDL_RenderPresent(renderer);
    // hien thi man hinh
}
