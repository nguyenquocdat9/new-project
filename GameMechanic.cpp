#include <SDL.h>
#include <SDL_image.h>
#include "GameMechanic.h"

bool CheckColisionAxisX(int x1, int x2)
{
    if(abs(x2 - x1) < 80) return true;
    else return false;
}

bool CheckColisionAxisY(int y1, int y2)
{
    if(abs(y2 - y1) < 90) return true;
    else return false;
}

// width = 80, height = 90
bool CheckCollision(int x1, int y1, int x2, int y2)
{
    if(CheckColisionAxisX(x1, x2) && CheckColisionAxisY(y1, y2)) return true;
    else return false;
}

bool ShieldObtained(int Xship, int Yship, int xShield, int yShield)
{
    if(CheckCollision(Xship, Yship, xShield, yShield)) return true;
    else return false;
}

bool ShieldTimer(clock_t ElapsedTime, int TimeSpawn)
{
    if(ElapsedTime / CLK_TCK >= TimeSpawn) return true;
    else return false;
}
