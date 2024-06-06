#include "board.h"
#include <iostream>

void board::print() const
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << b[i][j];
            if (j < 2)
            {
                std::cout << '|';
            }
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "-+-+-" << std::endl;
    }
    std::cout << std::endl;
}

void board::printBoardNums() const
{
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << num++;
            if (j < 2)
            {
                std::cout << '|';
            }
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "-+-+-" << std::endl;
    }
    std::cout << std::endl;
}

bool board::set(int num, char c)
{
    if (num < 0 || num > 8)
    {
        std::cout << "Input must be between 1 and 9\n";
        return false;
    }

    if (b[num/3][num%3] != ' ')
    {
        std::cout << "Position already taken\n";
        return false;
    }

    b[num/3][num%3] = c;
    return true;
}

bool board::checkWin(char c) const
{
    for (int i = 0; i < 3; i++)
    {
        if (b[i][0] == c && b[i][1] == c && b[i][2] == c)
            return true;

        if (b[0][i] == c && b[1][i] == c && b[2][i] == c)
            return true;
    }

    if (b[0][0] == c && b[1][1] == c && b[2][2] == c)
        return true;

    if (b[0][2] == c && b[1][1] == c && b[2][0] == c)
        return true;

    return false;
}

bool board::checkTie() const
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (b[i][j] == ' ')
                return false;
        }
    }

    return true;
}

void board::reset()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[i][j] = ' ';
        }
    }
}


