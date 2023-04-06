#ifndef MECHANIC_H
#define MECHANIC_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

bool CheckColisionAxisX(int x1, int x2);

bool CheckColisionAxisY(int y1, int y2);

bool CheckCollision(int x1, int y1, int x2, int y2);

bool ShieldObtained(int Xship, int Yship, int xShield, int yShield);

bool ShieldSpawn(clock_t ElapsedTime, int TimeSpawn);


#endif // MECHANIC_H

