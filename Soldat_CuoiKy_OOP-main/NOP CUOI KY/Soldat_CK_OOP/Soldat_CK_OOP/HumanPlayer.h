#pragma once
#include "Board.h"
#include "Player.h"

// Lop nguoi choi la con nguoi, ke thua tu lop Player
class HumanPlayer : public Player
{
public:
    HumanPlayer(char sym) : Player(sym) {} // Khoi tao ky tu cho nguoi choi la con nguoi

    int makeMove(Board& board) override
    {
        int position;
        cout << "Enter position (1-9): ";

        while (!(cin >> position) || position < 1 || position > 9 || !board.isCellEmpty(position))
        {
            cout << "Invalid input! Please enter a valid position (1-9): ";
            cin.clear(); // Xoa trang thai loi cua cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (cin.fail())
            {
                cout << "Invalid input! Please enter a number between 1 and 9: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        return position;
    }
};

