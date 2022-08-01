#include <bits/stdc++.h>
using namespace std;

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