#include <iostream>
#include <vector>
using namespace std;

int solve(int index, vector<int> &num, int tar, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (tar == 0 && num[index] == 0)
            return 2;
        if (tar == 0 || num[index] == tar)
            return 1;
        return 0;
    }

    if (dp[index][tar] != -1)
        return dp[index][tar];

    int notPick = solve(index - 1, num, tar, dp);
    int pick = 0;
    if (num[index] <= tar)
        pick = solve(index - 1, num, tar - num[index], dp);

    return dp[index][tar] = pick + notPick;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return solve(n - 1, num, tar, dp);
}