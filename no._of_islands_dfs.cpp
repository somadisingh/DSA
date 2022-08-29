#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void markIsland(int i, int j, int row, int col, vector<vector<char>> &grid)
    {
        if (grid[i][j] == '1')
        {
            grid[i][j] = '0';
        }
        else
            return;

        if (j - 1 >= 0)
            markIsland(i, j - 1, row, col, grid);
        if (j + 1 < col)
            markIsland(i, j + 1, row, col, grid);
        if (i - 1 >= 0)
            markIsland(i - 1, j, row, col, grid);
        if (i + 1 < row)
            markIsland(i + 1, j, row, col, grid);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    markIsland(i, j, m, n, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << s.numIslands(grid) << endl;
    return 0;
}