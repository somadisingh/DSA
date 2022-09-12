#include <iostream>
#include <vector>

using namespace std;

// memoization
class Solution
{
public:
    int f(int ind, bool buy, vector<int> &v, int fee, vector<vector<int>> &dp)
    {
        if (ind == v.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy)
        {
            return dp[ind][buy] = max(-v[ind] + f(ind + 1, 0, v, fee, dp), f(ind + 1, 1, v, fee, dp));
        }
        return dp[ind][buy] = max(v[ind] - fee + f(ind + 1, 1, v, fee, dp), f(ind + 1, 0, v, fee, dp));
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);
    }
};

// tabulation

int maxProfit(vector<int> &prices, int fee)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
    }

    return dp[0][1];
}

// space optimized

int maxProfit(vector<int> &prices, int fee)
{
    vector<int> aft(2, 0), curr(2, 0);
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        curr[1] = max(-prices[i] + aft[0], aft[1]);
        curr[0] = max(prices[i] - fee + aft[1], aft[0]);
        aft = curr;
    }

    return aft[1];
}