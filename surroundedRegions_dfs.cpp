#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void markOut(int i, int j, int row, int col, vector<vector<char>> &board, vector<vector<bool>> &vis)
    {
        if (i < 0 || j < 0 || i >= row || j >= col || vis[i][j] || board[i][j] == 'X')
            return;

        vis[i][j] = 1;

        markOut(i - 1, j, row, col, board, vis);
        markOut(i + 1, j, row, col, board, vis);
        markOut(i, j - 1, row, col, board, vis);
        markOut(i, j + 1, row, col, board, vis);

        return;
    }

public:
    void solve(vector<vector<char>> &board)
    {

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        // traverse first and last column
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && !vis[i][0])
                markOut(i, 0, m, n, board, vis);
            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
                markOut(i, n - 1, m, n, board, vis);
        }

        // traverse first and last row
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O' && !vis[0][j])
                markOut(0, j, m, n, board, vis);
            if (board[m - 1][j] == 'O' && !vis[m - 1][j])
                markOut(m - 1, j, m, n, board, vis);
        }

        // traverse the board and mark all the 'O' with 'X' which are not marked
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};