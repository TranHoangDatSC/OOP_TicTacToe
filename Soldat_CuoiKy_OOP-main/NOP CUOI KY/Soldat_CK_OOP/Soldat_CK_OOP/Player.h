#pragma once
#include "Board.h"

class Player
{
private:
    char symbol;

public:
    Player(char sym) : symbol(sym) {} // Khoi tao ky tu 

    virtual int makeMove(Board& board) = 0; // Ham thuan ao
};


