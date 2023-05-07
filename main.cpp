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
                   , Entity& asteroid5, Entity& asteroid6, bool MoreObj, Entity& Shield, bool ShieldUp, bool ShieldDisappear, bool ShieldGot, Entity& Buff, bool BuffUp, bool BuffDisappear, bool BuffGot);

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Texture* background = loadTexture("image/background.jpg", renderer);
    SDL_Texture* mainmenu = loadTexture("image/mainmenu.jpg", renderer);
    //setting
    int PickShip = 1, PickMus = 1;
    SDL_Texture* Ship1Mus1 = loadTexture("image/option/ship1mus1.jpg", renderer);
    SDL_Texture* Ship1Mus2 = loadTexture("image/option/ship1mus2.jpg", renderer);
    SDL_Texture* Ship1Mus3 = loadTexture("image/option/ship1mus3.jpg", renderer);
    SDL_Texture* Ship1Mus4 = loadTexture("image/option/ship1mus4.jpg", renderer);
    SDL_Texture* Ship1Mus5 = loadTexture("image/option/ship1mus5.jpg", renderer);
    SDL_Texture* Ship1Mus6 = loadTexture("image/option/ship1mus6.jpg", renderer);
    SDL_Texture* Ship1Mus7 = loadTexture("image/option/ship1mus7.jpg", renderer);
    SDL_Texture* Ship1Mus8 = loadTexture("image/option/ship1mus8.jpg", renderer);
    SDL_Texture* Ship1Mus9 = loadTexture("image/option/ship1mus9.jpg", renderer);
    SDL_Texture* Ship2Mus1 = loadTexture("image/option/ship2mus1.jpg", renderer);
    SDL_Texture* Ship2Mus2 = loadTexture("image/option/ship2mus2.jpg", renderer);
    SDL_Texture* Ship2Mus3 = loadTexture("image/option/ship2mus3.jpg", renderer);
    SDL_Texture* Ship2Mus4 = loadTexture("image/option/ship2mus4.jpg", renderer);
    SDL_Texture* Ship2Mus5 = loadTexture("image/option/ship2mus5.jpg", renderer);
    SDL_Texture* Ship2Mus6 = loadTexture("image/option/ship2mus6.jpg", renderer);
    SDL_Texture* Ship2Mus7 = loadTexture("image/option/ship2mus7.jpg", renderer);
    SDL_Texture* Ship2Mus8 = loadTexture("image/option/ship2mus8.jpg", renderer);
    SDL_Texture* Ship2Mus9 = loadTexture("image/option/ship2mus9.jpg", renderer);
    SDL_Texture* Ship3Mus1 = loadTexture("image/option/ship3mus1.jpg", renderer);
    SDL_Texture* Ship3Mus2 = loadTexture("image/option/ship3mus2.jpg", renderer);
    SDL_Texture* Ship3Mus3 = loadTexture("image/option/ship3mus3.jpg", renderer);
    SDL_Texture* Ship3Mus4 = loadTexture("image/option/ship3mus4.jpg", renderer);
    SDL_Texture* Ship3Mus5 = loadTexture("image/option/ship3mus5.jpg", renderer);
    SDL_Texture* Ship3Mus6 = loadTexture("image/option/ship3mus6.jpg", renderer);
    SDL_Texture* Ship3Mus7 = loadTexture("image/option/ship3mus7.jpg", renderer);
    SDL_Texture* Ship3Mus8 = loadTexture("image/option/ship3mus8.jpg", renderer);
    SDL_Texture* Ship3Mus9 = loadTexture("image/option/ship3mus9.jpg", renderer);
    //obstacle
    SDL_Texture* obstacle1 = loadTexture("image/meteor1.png", renderer);
    SDL_Texture* obstacle2 = loadTexture("image/meteor2.png", renderer);
    //spaceship related
    SDL_Texture* barrier = loadTexture("image/shield.png", renderer);
    SDL_Texture* spaceship1 = loadTexture("image/ship/spaceship1.png", renderer);
    SDL_Texture* spaceship1Shield = loadTexture("image/ship/spaceship1withshield.png", renderer);
    SDL_Texture* spaceship2 = loadTexture("image/ship/spaceship2.png", renderer);
    SDL_Texture* spaceship2Shield = loadTexture("image/ship/spaceship2withshield.png", renderer);
    SDL_Texture* spaceship3 = loadTexture("image/ship/spaceship3.png", renderer);
    SDL_Texture* spaceship3Shield = loadTexture("image/ship/spaceship3withshield.png", renderer);
    //buff
    SDL_Texture* buff = loadTexture("image/slow.png", renderer);
    //menu
    SDL_Texture* GameOverScreen = loadTexture("image/gameover.jpg", renderer);

    // generate value
    //shield
    int TimeSpawn = 20; // 20sec
    int DisappearTime = 25;//5sec
    int FadingTime = 5; // shield time 5sec
    //slow buff
    int TimeSpawnBuff = 40;//40 sec
    int BuffDisappearTime = 45;//5 sec

    //
    bool GameIsRunning = false;
    bool QuitGame = false;
    bool MainMenuOn = true;
    bool SettingOn = false;
    bool GameOverOn = false;

    SDL_Event e;
    srand((unsigned int) time(NULL));
    //ship
    SDL_Texture* ShipPhoto;
    SDL_Texture* ShipShieldPhoto;
    SDL_Texture* NorShip;
    ShipShieldPhoto = spaceship1Shield;
    NorShip = spaceship1;
    //setting
    SDL_Texture* setting;
    //gametempo
    int HardModeTime = 60;

  while(!QuitGame)
  {
    // 1, 3 spawn trai
    // 2, 4 spawn phai
    int Xship = SCREEN_WIDTH / 2, Yship = SCREEN_HEIGHT / 2;
    int x1 = -(rand() % 600) - 200;
    int y1 = (rand() % 700) + 1;
    int x2 = (rand() % 600) + 1701;
    int y2 = (rand() % 700) + 1;
    int x3 = -(rand() % 600) - 200;
    int y3 = (rand() % 700) + 1;
    int x4 = (rand() % 600) + 1701;
    int y4 = (rand() % 700) + 1;
    int x5 = (rand() % 1400) + 1;
    int y5 = -(rand() % 600) - 200;
    int x6 = (rand() % 1400) + 1;
    int y6 = (rand() % 600) + 1000;
    //shield
    clock_t StartTime = clock();
    clock_t ShieldStartTime = 0;
    int xShield = (rand() % 1400) + 1;
    int yShield = (rand() % 696) + 1;
    bool Invulnerable = false;
    //game tempo
    int speed = 8;
    clock_t SpeedupTime = clock();
    clock_t AddObjTime = clock();
    bool AddMoreObj = false;
    //buff
    clock_t BuffStartTime = clock();
    int xBuff= (rand() % 1400) + 1;
    int yBuff = (rand() % 696) + 1;
    //setting
    setting = Ship1Mus1;

    while(MainMenuOn)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, mainmenu, NULL, NULL);
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
                if(e.button.x >= 640 && e.button.x <= 865 && e.button.y >= 260 && e.button.y <= 320) // PLAY Button
                {
                    GameIsRunning = true;
                    MainMenuOn = false;
                }
                if(e.button.x >= 645 && e.button.x <= 850 && e.button.y >= 495 && e.button.y <= 550) // QUIT Button
                {
                    QuitGame = true;
                    MainMenuOn = false;
                }
                if(e.button.x >= 555 && e.button.x <= 945 && e.button.y >= 380 && e.button.y <= 445) // SETTING Button
                {
                    SettingOn = true;
                    MainMenuOn = false;
                }
            }
        }
    }
    while(SettingOn)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, setting, NULL, NULL);
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
                if(e.button.x >= 0 && e.button.x <= 190 && e.button.y >= 735 && e.button.y <= 800) // BACK Button
                {
                    SettingOn = false;
                    MainMenuOn = true;
                }
                if(e.button.x >= 348 && e.button.x <= 580 && e.button.y >= 400 && e.button.y <= 650)
                {
                    PickShip = 1;
                    NorShip = spaceship1;
                    ShipShieldPhoto = spaceship1Shield;
                }
                if(e.button.x >= 750 && e.button.x <= 985 && e.button.y >= 400 && e.button.y <= 645)
                {
                    PickShip = 2;
                    NorShip = spaceship2;
                    ShipShieldPhoto = spaceship2Shield;
                }
                if(e.button.x >= 1150 && e.button.x <= 1350 && e.button.y >= 400 && e.button.y <= 645)
                {
                    PickShip = 3;
                    NorShip = spaceship3;
                    ShipShieldPhoto = spaceship3Shield;
                }
                if(e.button.x >= 255 && e.button.x <= 640 && e.button.y >= 10 && e.button.y <= 50)
                {
                    PickMus = 1;
                }
                if(e.button.x >= 695 && e.button.x <= 1080 && e.button.y >= 10 && e.button.y <= 50)
                {
                    PickMus = 2;
                }
                if(e.button.x >= 1120 && e.button.x <= 1500 && e.button.y >= 10 && e.button.y <= 50)
                {
                    PickMus = 3;
                }
                if(e.button.x >= 255 && e.button.x <= 640 && e.button.y >= 120 && e.button.y <= 160)
                {
                    PickMus = 4;
                }
                if(e.button.x >= 695 && e.button.x <= 1080 && e.button.y >= 120 && e.button.y <= 160)
                {
                    PickMus = 5;
                }
                if(e.button.x >= 1120 && e.button.x <= 1500 && e.button.y >= 120 && e.button.y <= 160)
                {
                    PickMus = 6;
                }
                if(e.button.x >= 255 && e.button.x <= 640 && e.button.y >= 230 && e.button.y <= 260)
                {
                    PickMus = 7;
                }
                if(e.button.x >= 695 && e.button.x <= 1080 && e.button.y >= 230 && e.button.y <= 260)
                {
                    PickMus = 8;
                }
                if(e.button.x >= 1120 && e.button.x <= 1500 && e.button.y >= 230 && e.button.y <= 260)
                {
                    PickMus = 9;
                }
            }
        if(PickShip == 1)
        {
            if(PickMus == 1)setting = Ship1Mus1;
            else if(PickMus == 2)setting = Ship1Mus2;
            else if(PickMus == 3)setting = Ship1Mus3;
            else if(PickMus == 4)setting = Ship1Mus4;
            else if(PickMus == 5)setting = Ship1Mus5;
            else if(PickMus == 6)setting = Ship1Mus6;
            else if(PickMus == 7)setting = Ship1Mus7;
            else if(PickMus == 8)setting = Ship1Mus8;
            else if(PickMus == 9)setting = Ship1Mus9;
        }
        else if(PickShip == 2)
        {
            if(PickMus == 1)setting = Ship2Mus1;
            else if(PickMus == 2)setting = Ship2Mus2;
            else if(PickMus == 3)setting = Ship2Mus3;
            else if(PickMus == 4)setting = Ship2Mus4;
            else if(PickMus == 5)setting = Ship2Mus5;
            else if(PickMus == 6)setting = Ship2Mus6;
            else if(PickMus == 7)setting = Ship2Mus7;
            else if(PickMus == 8)setting = Ship2Mus8;
            else if(PickMus == 9)setting = Ship2Mus9;
        }
        else if(PickShip == 3)
        {
            if(PickMus == 1)setting = Ship3Mus1;
            else if(PickMus == 2)setting = Ship3Mus2;
            else if(PickMus == 3)setting = Ship3Mus3;
            else if(PickMus == 4)setting = Ship3Mus4;
            else if(PickMus == 5)setting = Ship3Mus5;
            else if(PickMus == 6)setting = Ship3Mus6;
            else if(PickMus == 7)setting = Ship3Mus7;
            else if(PickMus == 8)setting = Ship3Mus8;
            else if(PickMus == 9)setting = Ship3Mus9;
        }
        }


    }
    //ship
    ShipPhoto = NorShip;
    //music
    if(GameIsRunning)
    {
        Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
        Mix_Music *Theme = NULL;
        if(PickMus == 1)Theme = Mix_LoadMUS("music/PurpleRain.mp3");
        else if(PickMus == 2)Theme = Mix_LoadMUS("music/Granite.mp3");
        else if(PickMus == 3)Theme = Mix_LoadMUS("music/Starfall.mp3");
        else if(PickMus == 4)Theme = Mix_LoadMUS("music/Airborne_Robots.mp3");
        else if(PickMus == 5)Theme = Mix_LoadMUS("music/[Electro] Nitro Fun - Cheat Codes [Monstercat Release].mp3");
        else if(PickMus == 6)Theme = Mix_LoadMUS("music/DJVI - Back On Track.mp3");
        else if(PickMus == 7)Theme = Mix_LoadMUS("music/still yearning.mp3");
        else if(PickMus == 8)Theme = Mix_LoadMUS("music/Sol.mp3");
        else if(PickMus == 9)Theme = Mix_LoadMUS("music/Mt. Gael.mp3");
        Mix_PlayMusic(Theme, 30);
    }
    while(GameIsRunning)
    {
        int start = SDL_GetTicks();
        // check if asteroid is rendered
        Entity *asteroid1 = new Entity(x1, y1, obstacle1);
        asteroid1->type = "asteroid1";
        Entity *asteroid2 = new Entity(x2, y2, obstacle1);
        asteroid2->type = "asteroid2";
        Entity *asteroid3 = new Entity(x3, y3, obstacle1);
        asteroid3->type = "asteroid3";
        Entity *asteroid4 = new Entity(x4, y4, obstacle1);
        asteroid4->type = "asteroid4";
        Entity *asteroid5 = new Entity(x5, y5, obstacle2);
        asteroid5->type = "asteroid5";
        Entity *asteroid6 = new Entity(x6, y6, obstacle2);
        asteroid6->type = "asteroid6";
        //check render spaceship
        Entity Ship(Xship, Yship, ShipPhoto);
        Ship.type = "ship";
        //shield related
        Entity *Shield = new Entity(xShield, yShield, barrier);
        Shield->type = "Shield";
        //buff related
        Entity *SlowBuff = new Entity(xBuff, yBuff, buff);
        SlowBuff->type = "buff";

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
          while( SDL_PollEvent(&e) != 0 ){
        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
          if (e.type == SDL_QUIT)
          {
              GameIsRunning = false;
              QuitGame = true;
          }
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
        //shield
        clock_t SpawnElapsedTime = clock() - StartTime;
        clock_t DisappearElapsedTime = clock() - StartTime;

        if(ShieldTimer(SpawnElapsedTime, TimeSpawn) && ShieldTimer(DisappearElapsedTime, DisappearTime) == false)
        {
            if(ShieldObtained(Xship, Yship, xShield, yShield))
            {
                ShipPhoto = ShipShieldPhoto;
                xShield = (rand() % 1400) + 1;
                yShield = (rand() % 696) + 1;
                StartTime = clock();
                ShieldStartTime = clock();
                Invulnerable = true;
            }
        }
        clock_t FadingElapsedTime = clock() - ShieldStartTime;
        if(ShieldTimer(FadingElapsedTime, FadingTime))
        {
            ShipPhoto = NorShip;
            Invulnerable = false;
        }
        //buff
        clock_t BuffSpawnElapsedTime = clock() - BuffStartTime;

        if(ShieldTimer(BuffSpawnElapsedTime, TimeSpawnBuff) && ShieldTimer(BuffSpawnElapsedTime, BuffDisappearTime) == false)
        {
            if(CheckCollision(Xship, Yship, xBuff, yBuff))
            {
                xBuff= (rand() % 1400) + 1;
                yBuff = (rand() % 696) + 1;
                speed -= 3;
                BuffStartTime = clock();
            }
        }

        refreshScreen(window, renderer, background, Ship, *asteroid1, *asteroid2, *asteroid3, *asteroid4, *asteroid5, *asteroid6, AddMoreObj, *Shield, ShieldTimer(SpawnElapsedTime, TimeSpawn)
                      , ShieldTimer(DisappearElapsedTime, DisappearTime), ShieldObtained(Xship, Yship, xShield, yShield), *SlowBuff, ShieldTimer(BuffSpawnElapsedTime, TimeSpawnBuff)
                      , ShieldTimer(BuffSpawnElapsedTime, BuffDisappearTime), CheckCollision(Xship, Yship, xBuff, yBuff));
        //if shield not obtained after DisappearTime reset StartTime and shield location
        if(ShieldTimer(DisappearElapsedTime, DisappearTime))
        {
            xShield = (rand() % 1400) + 1;
            yShield = (rand() % 696) + 1;
            StartTime = clock();
        }
        //buff
        if(ShieldTimer(BuffSpawnElapsedTime, BuffDisappearTime))
        {
            xBuff= (rand() % 1400) + 1;
            yBuff = (rand() % 696) + 1;
            BuffStartTime = clock();
        }
        //delete all dynamic variable
        delete asteroid1;
        delete asteroid2;
        delete asteroid3;
        delete asteroid4;
        delete asteroid5;
        delete asteroid6;
        delete Shield;
        delete SlowBuff;

        // object
        clock_t SpeedUpElapsed = clock() - SpeedupTime;
        if(ShieldTimer(SpeedUpElapsed, DisappearTime))
        {
            speed += 2;
            SpeedupTime = clock();
        }
        clock_t AddObjElapsed = clock() - AddObjTime;
        if(ShieldTimer(AddObjElapsed, HardModeTime))
        {
            AddMoreObj = true;
        }
        //change asteroid position
        x1 += speed;
        x2 -= speed;
        x3 += speed;
        x4 -= speed;
        if(AddMoreObj)
        {
            y5 += speed;
            y6 -= speed;
        }
        if(x1 >= 1500)
        {
            x1 = -(rand() % 600) + 1;
            y1 = (rand() % 696) + 1;
        }
        if(x2 <= -100)
        {
            x2 = (rand() % 600) + 1501;
            y2 = (rand() % 696) + 1;
        }
        if(x3 >= 1500)
        {
            x3 = -(rand() % 600) + 1;;
            y3 = (rand() % 696) + 1;
        }
        if(x4 <= -100)
        {
            x4 = (rand() % 600) + 1501;
            y4 = (rand() % 696) + 1;
        }
        if(y5 >= 800)
        {
            x5 = (rand() % 1400) + 1;
            y5 = -(rand() % 600) + 1;
        }
        if(y6 <= -100)
        {
            x6 = (rand() % 1400) + 1;
            y6 = (rand() % 600) + 801;
        }
        //check collision
        if(CheckCollision(Xship, Yship, x1, y1))
        {
            if(Invulnerable == false)
            {
                GameIsRunning = false;
                cout << "collided" << endl;
            }
        }
        if(CheckCollision(Xship, Yship, x2, y2))
        {
            if(Invulnerable == false)
            {
                GameIsRunning = false;
                cout << "collided" << endl;
            }
        }
        if(CheckCollision(Xship, Yship, x3, y3))
        {
            if(Invulnerable == false)
            {
                GameIsRunning = false;
                cout << "collided" << endl;
            }
        }
        if(CheckCollision(Xship, Yship, x4, y4))
        {
            if(Invulnerable == false)
            {
                GameIsRunning = false;
                cout << "collided" << endl;
            }
        }
        if(CheckCollision(Xship, Yship, x5, y5) && AddMoreObj)
        {
            if(Invulnerable == false)
            {
                GameIsRunning = false;
                cout << "collided" << endl;
            }
        }
        if(CheckCollision(Xship, Yship, x6, y6) && AddMoreObj)
        {
            if(Invulnerable == false)
            {
                GameIsRunning = false;
                cout << "collided" << endl;
            }
        }

        //FPS stabilizer
        int delta = SDL_GetTicks() - start;
        if(delta < DELTA) SDL_Delay(DELTA - delta);
    }
    //Game Over Screen
    if(!GameIsRunning && !QuitGame && !MainMenuOn)
    {
        Mix_CloseAudio();
        GameOverOn = true;
    }
    while(GameOverOn)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, GameOverScreen, NULL, NULL);
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
                if(e.button.x >= 609 && e.button.x <= 895 && e.button.y >= 490 && e.button.y <= 575) // button PLAY AGAIN 609 -> 895 ; 490 -> 575
                {
                    GameOverOn = false;
                    GameIsRunning = true;
                }
                if(e.button.x >= 609 && e.button.x <= 895 && e.button.y >= 691 && e.button.y <= 772) // button QUIT GAME 609 -> 895 ; 691 -> 772
                {
                    GameOverOn = false;
                    QuitGame = true;
                }
                if(e.button.x >= 609 && e.button.x <= 895 && e.button.y >= 585 && e.button.y <= 675) // button MAIN MENU button QUIT GAME 609 ; 585 -> 675
                {
                    GameOverOn = false;
                    MainMenuOn = true;
                }
            }
        }
    }
  }

    quitSDL(window, renderer);
    return 0;
}

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* background, Entity& Ship, Entity& asteroid1, Entity& asteroid2, Entity& asteroid3, Entity& asteroid4
                    , Entity& asteroid5, Entity& asteroid6, bool MoreObj, Entity& Shield, bool ShieldUp, bool ShieldDisappear, bool ShieldGot, Entity& Buff, bool BuffUp, bool BuffDisappear, bool BuffGot)
{
    SDL_RenderClear(renderer);


    SDL_RenderCopy(renderer, background, NULL, NULL);
    // render background

    if(ShieldUp && ShieldDisappear == false && ShieldGot == false) render(Shield, renderer);
    // render shield

    if(BuffUp && BuffDisappear == false && BuffGot == false) render(Buff, renderer);
    //render buff

    render(asteroid1, renderer);
    render(asteroid2, renderer);
    render(asteroid3, renderer);
    render(asteroid4, renderer);
    if(MoreObj)
    {
        render(asteroid5, renderer);
        render(asteroid6, renderer);
    }
    //render obstacle

    render(Ship, renderer);
    // render ship
    SDL_RenderPresent(renderer);
    // hien thi man hinh
}
