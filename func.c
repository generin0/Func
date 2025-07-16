#include <windows.h>
#include <stdio.h>

void mouseMove(int x, int y, int duration, int steps) { 
    POINT currentPos;
    GetCursorPos(&currentPos);

    int startX = currentPos.x;
    int startY = currentPos.y;

    int deltaX = x - startX;
    int deltaY = y - startY;

    int delayPerStep = duration / steps;

    for (int i = 0; i <= steps; i++) {
        int newX = startX + (deltaX * i) / steps;
        int newY = startY + (deltaY * i) / steps;

        SetCursorPos(newX, newY);
        printf("Debug: %d %d\n", newX, newY);
        Sleep(delayPerStep);
    }
    SetCursorPos(currentPos.x, currentPos.y);
}

int main(void){
    /*x, y - cords where u want mouse to be
    duration - delay between ur current pos and the final one
    steps - how much steps you want to make for the whole cycle*/
    mouseMove(200, 600, 500, 100);
    return 0;
}
