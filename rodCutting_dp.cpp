#include <iostream>
#include <vector>
using namespace std;

// recursion with memoization
int f(int ind, int rodLen, vector<int> &price, vector<vector<int>> &dp)
{

    if (ind == 0)
        return (price[ind]) * rodLen;

    if (dp[ind][rodLen] != -1)
        return dp[ind][rodLen];

    int notPick = f(ind - 1, rodLen, price, dp);
    int pick = -1e9;
    if (rodLen >= ind + 1)
        pick = price[ind] + f(ind, (rodLen - (ind + 1)), price, dp);

    return dp[ind][rodLen] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}

int main()
{
    int n = 5;
    vector<int> price = {1, 2, 3, 4, 5};
    cout << cutRod(price, n) << endl;
    return 0;
}

// tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int rod = 0; rod <= n; rod++)
    {
        dp[0][rod] = price[0] * rod;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int rod = 0; rod <= n; rod++)
        {
            int notPick = dp[ind - 1][rod];
            int pick = -1e9;
            if (rod >= ind + 1)
                pick = price[ind] + dp[ind][rod - (ind + 1)];

            dp[ind][rod] = max(pick, notPick);
        }
    }
    return dp[n - 1][n];
}

// space optimized
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int rod = 0; rod <= n; rod++)
    {
        prev[rod] = price[0] * rod;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int rod = 0; rod <= n; rod++)
        {
            int notPick = prev[rod];
            int pick = -1e9;
            if (rod >= ind + 1)
                pick = price[ind] + curr[rod - (ind + 1)];

            curr[rod] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[n];
}