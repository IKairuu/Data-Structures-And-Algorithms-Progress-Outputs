#include <windows.h>
#include <cstdlib>

void gotoxy(int x, int y)
{
    COORD coordinates ;
    coordinates.X = x ;
    coordinates.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates) ;
}

int random(int num)
{
    return rand() % num ;
}