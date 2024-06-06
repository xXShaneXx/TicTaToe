#include <iostream>
#include "gameController.h"

void gameController::startGame() 
{
    std::cout << "Player 1: X, Player 2: O" << std::endl;
    int x;
    char c = 'X';

    b.printBoardNums();
    b.print();

    while (play)
    {
        std::cout << "Enter position for " << c << ": ";
        int x;
        while(true)
        {
            std::cin >> x;
            if (b.set(x, c))
                break;
            system("clear");
            b.printBoardNums();
            b.print();
            std::cout << "Try again: ";
        }
        

        if (b.checkWin(c))
        {
            std::system("clear");
            b.print();
            handleEndGame(c, play, std::string(1, c) + " wins!");
            continue;
        }

        if (b.checkTie())
            handleEndGame(c, play, "It's a tie!");

            c = (c == 'X') ? 'O' : 'X';

        std::system("clear");
        b.printBoardNums();
        b.print();
    }
}

char gameController::getAnswer() 
{
    char ans;
    while (true) 
    {
        std::cin >> ans;
        switch (ans) 
        {
            case 'y':
            case 'n':
                return ans;

            default:
                std::cout << "Invalid input. Please enter 'y' or 'n': ";
        }
    }
}

void gameController::handleEndGame(char c, bool& play, const std::string& message) 
{
    std::cout << message << std::endl;
    std::cout << "Do you want to play again? (y/n): ";
    char ans = getAnswer();
    if (ans == 'n')
        play = false;
    else
    {
        std::system("clear");
        b.reset();
        b.printBoardNums();
        b.print();
    }
}
