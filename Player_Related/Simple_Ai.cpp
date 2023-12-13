#include "Simple_Ai.h"
Coordinates Simple_Ai::Attack_Enemy()
{
int x =rand()%10;
int y =rand()%10;
Coordinates ai_cords;
ai_cords.x =x;
ai_cords.y =y;
    return ai_cords;
}