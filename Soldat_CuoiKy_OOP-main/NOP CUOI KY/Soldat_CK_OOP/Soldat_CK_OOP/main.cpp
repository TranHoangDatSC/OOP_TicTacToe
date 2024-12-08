#include <iostream>
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Game.h"

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    bool playAgain = true;
    while (playAgain) {
        cout << "Choose game mode:" << endl;
        cout << "1. Player vs. Player" << endl;
        cout << "2. Player vs. Computer" << endl;
        cout << "3. Computer vs. Computer" << endl;

        int choice; // Cho lua chon che do choi
        cin >> choice;

        Player* player1;
        Player* player2;
        char choiceSymbol; // Luu ky tu da chon

        switch (choice)
        {
        case 1: // Lua chon so 1: nguoi choi voi nguoi
            cout << "Player 1, choose X or O: ";
            cin >> choiceSymbol;    // Chon X hoac O
            if (choiceSymbol != 'X' && choiceSymbol != 'O') {   // Neu nhap khac X hoac O thi mac dinh se la X
                cout << YELLOW << "Invalid symbol! Default to X." << RESET << endl;
                choiceSymbol = 'X';
            }
            player1 = new HumanPlayer(choiceSymbol); // Nguoi choi 1 se chon ky tu minh muon 
            player2 = new HumanPlayer((choiceSymbol == 'X') ? 'O' : 'X'); // Nguoi choi 2 se chon ky tu doi lap
            break;
        case 2: // Lua chon so 2: nguoi choi voi may
            cout << "Choose X or O: ";
            cin >> choiceSymbol;    // nguoi choi la con nguoi se chon ky tu minh mong muon
            if (choiceSymbol != 'X' && choiceSymbol != 'O') {   // Neu chon nham khong co X hoac O, thi se mac dinh la X
                cout << YELLOW << "Invalid symbol! Default to X." << RESET << endl;
                choiceSymbol = 'X';
            }
            player1 = new HumanPlayer(choiceSymbol);// Nguoi choi la con nguoi se chon ky tu minh muon
            player2 = new ComputerPlayer((choiceSymbol == 'X') ? 'O' : 'X'); // Nguoi may se chon ky tu doi lap
            break;

        case 3:
            player1 = new ComputerPlayer('X');  // Nguoi may 1 chon ky tu X
            player2 = new ComputerPlayer('O');  // Nguoi may 2 chon ky tu Y
            choiceSymbol = 'X';
            break;
        default:
            cout << YELLOW << "Invalid choice!" << RESET << endl;
            return true;
        }

        Game game(player1, player2, choiceSymbol, choiceSymbol); //Khoi tao tro choi voi nguoi choi va bieu tuong da chon
        game.start(); // Bat dau tro choi

        delete player1; // Giai phong bo nho cho nguoi choi 1
        delete player2; // Giai phong bo nho cho nguoi choi 2

        cout << "Do you want to play again? (1: Yes, 2: No): ";
        int playChoice; // Chon 2 lua chon, choi lai la 1, nghi choi la 2
        cin >> playChoice;
        if (playChoice == 1)
            playAgain = true;
        else if (playChoice == 2)
            playAgain = false;
        else {
            cout << endl << YELLOW << "Invalid choice! Default to 2 - End Game!" << RESET << endl;
            playAgain = false;
        }
    }

    cout << GREEN << "Thank you for playing Tic Tac Toe!" << RESET << endl; // Neu nghi choi thi xuat ra cai nay

    return 0;
}

