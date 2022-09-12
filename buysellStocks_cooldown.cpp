#include <iostream>
#include <vector>

using namespace std;

// recursion + memoization
class Solution
{
public:
    int f(int ind, bool buy, vector<int> &v, vector<vector<int>> &dp)
    {
        if (ind >= v.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy)
            return dp[ind][buy] = max(-v[ind] + f(ind + 1, 0, v, dp), f(ind + 1, 1, v, dp));
        return dp[ind][buy] = max(v[ind] + f(ind + 2, 1, v, dp), f(ind + 1, 0, v, dp));
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};

// tabulation

int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
    for (int ind = prices.size() - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
                dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            else
                dp[ind][buy] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
        }
    }
    return dp[0][1];
}

// time optimized

int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
    // removed the inner buy loop
    for (int ind = prices.size() - 1; ind >= 0; ind--)
    {
        dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
        dp[ind][0] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
    }
    return dp[0][1];
}