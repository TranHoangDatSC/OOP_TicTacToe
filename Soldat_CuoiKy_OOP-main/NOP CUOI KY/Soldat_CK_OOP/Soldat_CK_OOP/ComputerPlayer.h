#pragma once
#include "Board.h"
#include "Player.h"

// Lop nguoi choi la may tinh, ke thua lop Player
class ComputerPlayer : public Player
{
public:
    ComputerPlayer(char sym) : Player(sym) {} // Khoi tao ky tu cho nguoi choi la may tinh

    int makeMove(Board& board) override
    {
        // Mo phong nguoi may choi kieu ngau nhien (random)
        srand(time(0));
        int position = rand() % 9 + 1;
        while (!board.isCellEmpty(position))
        {
            position = rand() % 9 + 1;
        }
        return position; // Tra ve vi tri nguoi may da chon de choi
    }
};
