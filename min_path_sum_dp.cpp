#include <iostream>
#include <vector>
using namespace std;

// solution using recursion and memoization
// time complexity: O(m*n)
// space complexity: O(m*n) + O(path length)
int minSum(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (x == 0 && y == 0)
        return grid[x][y];
    if (x < 0 || y < 0)
        return 1e9;

    if (dp[x][y] != -1)
        return dp[x][y];

    int up = grid[x][y] + minSum(x - 1, y, grid, dp);
    int left = grid[x][y] + minSum(x, y - 1, grid, dp);
    return dp[x][y] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minSum(n - 1, m - 1, grid, dp);
}

// solution using tabulation
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;
                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

// soltion using space optimization

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;
                int left = grid[i][j];
                if (j > 0)
                    left += curr[j - 1];
                else
                    left += 1e9;
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}