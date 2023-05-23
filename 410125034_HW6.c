#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

void clearScreen()
{
    system("cls");
}

void setCursorPosition(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawText(int x, int y, const char* text, int color)
{
    setCursorPosition(x, y);
    setColor(color);
    printf("%s", text);
}

void updateCoordinates(int* x, int* y, int* dx, int* dy, int* color)
{
    if (*x <= 0 || *x >= SCREEN_WIDTH - strlen("Hello")) {
        *dx = -*dx; // reverse horizontal direction
        setColor(rand() % 15 + 1); // change text color randomly
    }

    if (*y <= 0 || *y >= SCREEN_HEIGHT) {
        *dy = -*dy; // reverse vertical direction
        *color = rand() % 15 + 1; // change text color randomly
    }

    *x += *dx; // update x coordinate
    *y += *dy; // update y coordinate
}

int main()
{
    int x = SCREEN_WIDTH / 2;
    int y = SCREEN_HEIGHT / 2;
    int dx = 1;
    int dy = 1;
    char* text = "XXXXX";
    int color = rand() % 15 + 1;

    srand((unsigned int)time(NULL));

    while (!kbhit()) { // exit loop when a key is pressed
        clearScreen();
        updateCoordinates(&x, &y, &dx, &dy, &color);
        drawText(x, y, text, color);
        setCursorPosition(0, SCREEN_HEIGHT + 1);
        printf("Current position: x = %d, y = %d", x, y);
        Sleep(200); // delay 200 milliseconds
    }

    return 0;
}
/*THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 ³¯«\Ê¹*/
