#include <iostream>
#include <string>
using namespace std;
const int ROWS = 3;
const int COLS = 3;
void runGame();
void intializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xtrun, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);
int main()
{
    runGame();

    return 0;
}
void runGame()
{
    string winner = "";
    bool xturn = true;
    string gameBoard[ROWS][COLS];
    intializeGameBoard(gameBoard);
    printCurrentBoard(gameBoard);
    while (winner == "")
    {
        if (xturn)
        {
            cout << "It is X's turn " << endl;
        }
        else
        {
            cout << "It is O's turn" << endl;
        }
        getUserInput(xturn, gameBoard);
        cout << endl;
        printCurrentBoard(gameBoard);
        winner = getWinner(gameBoard);
        xturn = !xturn;
        if ((winner == "") && (isBoardFull(gameBoard)))
        {
            winner = "C";
        }
    }
    if (winner == "C")
    {
        cout << "It's a Cat game." << endl;
    }
    else
    {
        cout << winner << " is the winner." << endl;
    }
}
void intializeGameBoard(string gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = " ";
        }
    }
}
void printCurrentBoard(string gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << gameBoard[i][j];
            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "- - - " << endl;
        }
    }
    cout << endl;
}
void getUserInput(bool xtrun, string gameBoard[ROWS][COLS])
{
    int row, col;
    bool check = true;
    while (check)
    {
        cout << "Enter the row and column separated by a space(0,1,2)." << endl;
        cin >> row;
        cin >> col;
        if (!cellAlreadyOccupied(row, col, gameBoard))
        {
            check = false;
        }
        else
        {
            cout << "The cell is already ocuupied" << endl;
        }
    }
    if (xtrun)
    {
        gameBoard[row][col] = "X";
    }
    else
    {
        gameBoard[row][col] = "O";
    }
}
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS])
{
    bool res = true;
    if (gameBoard[row][col] == " ")
        res = false;
    return res;
}
string getWinner(string gameBoard[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
        {
            return gameBoard[i][0];
        }
    }
    for (int i = 0; i < COLS; i++)
    {
        if (gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
        {
            return gameBoard[0][i];
        }
    }
    if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
    {
        return gameBoard[0][0];
    }
    if (gameBoard[0][2] != " " && gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0])
    {
        return gameBoard[0][2];
    }
    return "";
}
bool isBoardFull(string gameBoard[ROWS][COLS])
{
    bool res = true;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (gameBoard[i][j] == " ")
            {
                res = false;
                break;
            }
        }
    }
    return res;
}