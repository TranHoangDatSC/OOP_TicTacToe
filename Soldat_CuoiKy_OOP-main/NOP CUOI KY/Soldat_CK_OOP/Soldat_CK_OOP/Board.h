#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>

using namespace std;

// Dinh nghia mau code
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#pragma once
// Lop bang cho game
class Board
{
private:
    vector<vector<char>> grid; // Ma tran luu trang thai cho bang
public:
    Board()
    {
        // Khoi tao bang trong
        grid = { {'1', '2', '3'},
                 {'4', '5', '6'},
                 {'7', '8', '9'} };
    }

    // Hien thi bang voi mau cua tung ky tu tuong ung
    void display()
    {
        cout << endl << "-------------" << endl;
        for (int i = 0; i < 3; ++i)
        {
            cout << "| ";
            for (int j = 0; j < 3; ++j)
            {
                // Kiem tra ky tu va dung dung mau cho ky tu do, o day X la do, O la xanh 
                if (grid[i][j] == 'X')
                    cout << RED << grid[i][j] << RESET << " | ";
                else if (grid[i][j] == 'O')
                    cout << BLUE << grid[i][j] << RESET << " | ";
                else
                    cout << grid[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }


    // Kiem tra chien thang
    bool checkWin() {
        // Kiem tra hang va cot
        for (int i = 0; i < 3; ++i)
        {
            if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) return true;
            if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) return true;
        }
        // Kiem tra duong cheo
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) return true; // Kiem tra duong cheo thu nhat
        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) return true; // Kiem tra duong cheo thu hai
        return false;
    }

    // Dat vao ky tu vi tri da chon
    void placeMove(int position, char symbol)
    {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        grid[row][col] = symbol;
    }

    // Kiem tra o co bi trong hay khong
    bool isCellEmpty(int position)
    {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        return (grid[row][col] != 'X' && grid[row][col] != 'O');
    }

    // Kiem tra bang co bi day hay khong
    bool isBoardFull()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (grid[i][j] != 'X' && grid[i][j] != 'O')
                {
                    return false; // Co o trong thi tra ve false
                }
            }
        }
        return true; // Khong co o trong thi tra ve true
    }

};
