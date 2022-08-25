#include <iostream>
#include <vector>
using namespace std;

// solution using recursion and memoization
// time complexity: O(n*m)
// space complexity: O(n*m) + O(n)
int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= matrix[0].size())
        return -1e9;
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
    int diagleft = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);
    int diagright = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);

    return dp[i][j] = max(up, max(diagleft, diagright));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e9;
    for (int a = 0; a < m; a++)
    {
        maxi = max(maxi, solve(n - 1, a, matrix, dp));
    }
    return maxi;
}

// solution using tabulation
// time complexity: O(n*m) + O(m)
// space complexity: O(n*m)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // down path
            int down = matrix[i][j] + dp[i - 1][j];
            // diagonaly left path
            int diagleft = matrix[i][j];
            if (j - 1 >= 0) // check if j-1 is not out of bounds
                diagleft += dp[i - 1][j - 1];
            else
                diagleft += -1e9;
            // diagonaly right path
            int diagright = matrix[i][j];
            if (j + 1 < m) // check if j+1 is not out of bounds
                diagright += dp[i - 1][j + 1];
            else
                diagright += -1e9;

            dp[i][j] = max(down, max(diagleft, diagright));
        }
    }
    // return the largest element of last row
    int maxi = dp[n - 1][0];
    for (int j = 1; j < m; j++)
        maxi = max(maxi, dp[n - 1][j]);
    return maxi;
}

// space optimized solution
// time complexity: O(n*m) + O(m)
// space complexity: O(1)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0);
    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            int down = matrix[i][j] + prev[j];
            int diagleft = matrix[i][j];
            if (j - 1 >= 0)
                diagleft += prev[j - 1];
            else
                diagleft += -1e9;
            int diagright = matrix[i][j];
            if (j + 1 < m)
                diagright += prev[j + 1];
            else
                diagright += -1e9;

            curr[j] = max(down, max(diagleft, diagright));
        }
        prev = curr;
    }
    int maxi = prev[0];
    for (int j = 1; j < m; j++)
        maxi = max(maxi, prev[j]);
    return maxi;
}