#include <iostream>
#include <vector>
using namespace std;

// solution using recursion and memoization
class Solution
{

public:
    int traverse(int x, int y, int m, int n, vector<vector<int>> &dp)
    {

        if (x == m - 1 && y == n - 1)
            return 1;
        if (x > m - 1 || y > n - 1)
            return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        else
            return dp[x][y] = traverse(x + 1, y, m, n, dp) + traverse(x, y + 1, m, n, dp);
    }

public:
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = traverse(0, 0, m, n, dp);
        if (m != 1 && n != 1)
            return ans;
        return 1;
    }
};

// solution using tabulation
class Solution
{

public:
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
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
};

// solution using space optimization
int uniquePaths(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        curr[0] = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}