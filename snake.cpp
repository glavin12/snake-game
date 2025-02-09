#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

const int width = 80;
const int height = 20;
int snakeX, snakeY;
int fruitCordX, fruitCordY;
int playerScore;
int snakeTailX[100], snakeTailY[100];
int snakeTailLength;
enum SnakeDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
SnakeDirection currentDirection;
bool isGameOver;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

void HideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void SetColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void GameInit() {
    isGameOver = false;
    currentDirection = STOP;
    snakeX = width / 2;
    snakeY = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
    snakeTailLength = 0;
}

void GameRender(const string& playerName, int snakeColor) {
    SetCursorPosition(0, 0);

    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (j == 0 || j == width)
                cout << "|";
            else if (i == snakeY && j == snakeX) {
                SetColor(snakeColor);
                cout << "O";
            }
            else if (i == fruitCordY && j == fruitCordX) {
                SetColor(12);
                cout << "#";
            }
            else {
                bool prTail = false;
                for (int k = 0; k < snakeTailLength; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        SetColor(snakeColor);
                        cout << "o";
                        prTail = true;
                        break;
                    }
                }
                if (!prTail) {
                    SetColor(7);
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    SetColor(7);
    cout << playerName << "'s Score: " << playerScore << endl;
}

int GetNextColor(int currentColor) {
    switch (currentColor) {
        case 10: return 11;
        case 11: return 12;
        case 12: return 13;
        case 13: return 14;
        case 14: return 15;
        default: return 10;
    }
}

void UpdateGame(int &snakeColor) {
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = snakeX;
    snakeTailY[0] = snakeY;

    for (int i = 1; i < snakeTailLength; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (currentDirection) {
    case LEFT:
        snakeX--;
        break;
    case RIGHT:
        snakeX++;
        break;
    case UP:
        snakeY--;
        break;
    case DOWN:
        snakeY++;
        break;
    }

    if (snakeX >= width || snakeX < 0 || snakeY >= height || snakeY < 0)
        isGameOver = true;

    for (int i = 0; i < snakeTailLength; i++) {
        if (snakeTailX[i] == snakeX && snakeTailY[i] == snakeY)
            isGameOver = true;
    }

    if (snakeX == fruitCordX && snakeY == fruitCordY) {
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLength++;
        snakeColor = GetNextColor(snakeColor);
    }
}

void UserInput() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            currentDirection = LEFT;
            break;
        case 'd':
            currentDirection = RIGHT;
            break;
        case 'w':
            currentDirection = UP;
            break;
        case 's':
            currentDirection = DOWN;
            break;
        case 'x':
            isGameOver = true;
            break;
        }
    }
}

int main() {
    string playerName = "Player"; 
    int dfc = 100; 

    GameInit();
    HideCursor();
    int snakeColor = 10;

    while (!isGameOver) {
        GameRender(playerName, snakeColor);
        UserInput(); 
        UpdateGame(snakeColor);
        Sleep(dfc);
    }

    return 0;
}