#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "board.h"

class gameController
{
    board b;
    bool play = true;
    char getAnswer();
    void handleEndGame(char c, bool& play, const std::string& message); 

public:
    gameController() : b() {}
    void startGame();
};

#endif // GAMECONTROLLER_H