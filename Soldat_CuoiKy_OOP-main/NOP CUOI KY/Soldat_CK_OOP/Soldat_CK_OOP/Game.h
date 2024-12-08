#pragma once
#include "Board.h"
#include "Player.h"

// LLop game
class Game {
private:
    Board board;
    Player* player1;
    Player* player2;
    char symbol; // Luu chu ky tu cua nguoi choi
    char startingSymbol; // Ky tu bat dau
    char choiceSymbol; // Ky tu ma nguoi choi chon

public:
    // Khoi tao voi hai nguoi choi, bieu tuong bat dau, ky tu duoc chon
    Game(Player* p1, Player* p2, char startSym, char choiceSym) : player1(p1), player2(p2), symbol(startSym), startingSymbol(startSym), choiceSymbol(choiceSym) {}

    // Bat dau tro choi
    void start() {
        board.display(); // Hien thi bang
        Player* currentPlayer = player1;
        while (!board.checkWin() && !board.isBoardFull()) // Neu nhu chu ai thang va bang van chua day
        {
            int move = currentPlayer->makeMove(board);  // Lay nuoc di tu nguoi choi hien tai
            board.placeMove(move, symbol);  // Dat nuoc di len bang
            board.display();    // Hien thi bang tro choi sau moi buoc di
            cout << endl << CYAN << "Player " << symbol << RESET << " placed a move on position " << move << endl << endl; // Thong bao nuoc di cua nguoi choi

            if (board.checkWin()) {
                cout << GREEN << "Player " << symbol << " wins!" << RESET << endl << endl;
                break; // Kiem tra nguoi chien thang
            }
            symbol = (symbol == 'X') ? 'O' : 'X'; // Doi luot cho nguoi choi
            if (currentPlayer == player1) currentPlayer = player2; // Neu nguoi choi hien tai la 1, doi qua cho nguoi choi thu 2
            else currentPlayer = player1; // Nguoc lai, thay doi lai thanh nguoi choi so 1
        }
        if (!board.checkWin() && board.isBoardFull()) {
            cout << YELLOW << "It's a draw!" << RESET << endl << endl; // Hien thi thong bao neu day la mot tran hoa
        }
    }

};
