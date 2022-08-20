#include <iostream>
#include <vector>
using namespace std;
// solution using recursion and memoization
class Solution
{
public:
    int traverse(int x, int y, int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (x == m - 1 && y == n - 1 && obstacleGrid[x][y] != 1)
            return 1;
        if (x > m - 1 || y > n - 1 || obstacleGrid[x][y] == 1)
            return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        return dp[x][y] = traverse(x + 1, y, m, n, obstacleGrid, dp) + traverse(x, y + 1, m, n, obstacleGrid, dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        if (m != 1 || n != 1)
            return traverse(0, 0, m, n, obstacleGrid, dp);
        else
        {
            if (obstacleGrid[0][0] == 0)
                return 1;
            else
                return 0;
        }
    }
};

// solution using tabulation
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else if (obstacleGrid[i][j] != 1)
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}