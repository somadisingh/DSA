#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp)
    {
        // base case
        if (amount == 0)
            return 0;
        else if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int mini = INT_MAX;
        // recursive relation
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solve(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }

        // memoization
        dp[amount] = mini;
        return mini;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};