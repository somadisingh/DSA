#include <iostream>
#include <vector>
using namespace std;

// solution using recursion and memoization
// time complexity: O(n*n)
// space complexity: O(n*n) + O(n)
int solve(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + solve(i + 1, j, n, triangle, dp);
    int diag = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);

    return dp[i][j] = min(down, diag);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(0, 0, n, triangle, dp);
}

// solution using tabulation
// time complexity: O(n*n)
// space complexity: O(n*n)
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diag);
        }
    }
    return dp[0][0];
}

// space optimized solution
// time complexity: O(n*n)
// space complexity: O(1)
int minimumPathSum(vector<vector<int>> &triangle, int n)
{

    vector<int> prev(n);
    for (int j = 0; j < n; j++)
    {
        prev[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n - 1);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + prev[j];
            int diag = triangle[i][j] + prev[j + 1];
            curr[j] = min(down, diag);
        }
        prev = curr;
    }
    return prev[0];
}
