#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define N 9

bool isSafe(int board[N][N],int row, int col,int num)
{
    for (int d = 0; d < N; d++)
    {
        if (board[row][d] == num)
        {
            return false;
        }
    }
    for (int r = 0; r < N; r++)
    {
        if (board[r][col] == num)
        {
            return false;
        }
    }
    int sqroot = (int)sqrt(N);
    int boxRowStart = row - row % sqroot;
    int boxColStart = col - col % sqroot;

    for (int r = boxRowStart; r < boxRowStart+sqroot; r++)
    {
        for (int d = boxColStart; d < boxColStart+sqroot; d++)
        {
            if (board[r][d] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int board[N][N], int n)
{
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
        {
            break;
        }
    }
    if (isEmpty)
    {
        return true;
    }
    for (int num = 1; num <= n; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;
            if (solveSudoku(board, n))
            {
                return true;
            }
            else
            {
                board[row][col] = 0;
            }
        }
    }
    return false;
}

void print(int board[N][N], int n)
{
    for (int r = 0; r < N; r++)
    {
        for (int d = 0; d < N; d++)
        {
            cout<<board[r][d]<<" ";
        }
        cout<<"\n";
        if ((r + 1)%(int)sqrt(N) == 0)
        {
            cout<<"";
        }
    }
}

int main()
{
    int grid[N][N];
    cout<<"Enter the contents of Sudoku(3x3) puzzle: "<<endl;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>grid[i][j];
    if (solveSudoku(grid,N) == true)
    {
        cout<<"Solved puzzle: "<<endl;
        print(grid,N);
    }
    else
        cout << "No solution exists";
    return 0;
}
