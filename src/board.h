#ifndef BOARD_H
#define BOARD_H

class board
{
    char b[3][3]{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

public:
    board() = default;
    void print() const;
    void printBoardNums() const;
    bool set(int x, char c);
    bool checkWin(char c) const;
    bool checkTie() const;
    void reset();
};

#endif // BOARD_H
