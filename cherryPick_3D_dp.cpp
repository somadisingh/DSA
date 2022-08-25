#include <iostream>
#include <vector>
using namespace std;

// solution using recursion and memoization
// time complexity: O(r*c^2)*9
// space complexity: O(r*c^2)*9 + O(r)
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    // base case: out of bounds
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;
    // base case: destination reached i.e. i==r-1
    if (i == r - 1)
    {
        // ended on the same block
        if (j1 == j2)
            return grid[i][j1];
        // ended on different blocks
        else
            return grid[i][j1] + grid[i][j2];
    }
    // memoisation fetch
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e8;
    for (int a = -1; a <= 1; a++)
    {
        for (int b = -1; b <= 1; b++)
        {
            int val = 0;
            if (j1 == j2)
                val = grid[i][j1];
            else
                val = grid[i][j1] + grid[i][j2];
            val += solve(i + 1, j1 + a, j2 + b, r, c, grid, dp);
            maxi = max(maxi, val);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // 3d table of dimensions r*c*c
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, 0, c - 1, r, c, grid, dp);
}

// solution using tabulation
// time complexity: O(r*c^2)*9
// space complexity: O(r*c^2)
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // 3d table of dimensions r*c*c
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    // BASE CASE
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;

                for (int a = -1; a <= 1; a++)
                {
                    for (int b = -1; b <= 1; b++)
                    {
                        int val = 0;
                        if (j1 == j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];
                        if (j1 + a >= 0 && j1 + a < c && j2 + b >= 0 && j2 + b < c)
                            val += dp[i + 1][j1 + a][j2 + b];
                        else
                            val += -1e8;
                        maxi = max(maxi, val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c - 1];
}