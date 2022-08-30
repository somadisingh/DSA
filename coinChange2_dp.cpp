/*
You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount.
If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.
*/

#include <iostream>
#include <vector>
using namespace std;

// recursion with memoization
class Solution
{
public:
    int f(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (ind == 0)
            return (tar % arr[ind] == 0);

        if (dp[ind][tar] != -1)
            return dp[ind][tar];

        int notPick = f(ind - 1, tar, arr, dp);
        int pick = 0;
        if (tar - arr[ind] >= 0)
            pick = f(ind, tar - arr[ind], arr, dp);

        return dp[ind][tar] = pick + notPick;
    }

public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};

// tabulation

int change(int amount, vector<int> &coins)
{

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int tar = 0; tar <= amount; tar++)
    {
        if (tar % coins[0] == 0)
            dp[0][tar] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= amount; tar++)
        {

            int notPick = dp[ind - 1][tar];
            int pick = 0;
            if (tar >= coins[ind])
                pick = dp[ind][tar - coins[ind]];

            dp[ind][tar] = pick + notPick;
        }
    }
    return dp[n - 1][amount];
}

// space optimized

int change(int amount, vector<int> &coins)
{

    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for (int tar = 0; tar <= amount; tar++)
    {
        if (tar % coins[0] == 0)
            prev[tar] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= amount; tar++)
        {

            int notPick = prev[tar];
            int pick = 0;
            if (tar >= coins[ind])
                pick = curr[tar - coins[ind]];

            curr[tar] = pick + notPick;
        }
        prev = curr;
    }
    return prev[amount];
}