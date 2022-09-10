#include <iostream>
#include <vector>

using namespace std;

// memoization

class Solution
{
public:
    int f(int index, int n, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == n)
            return 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if (buy)
        {
            profit = max(-prices[index] + f(index + 1, n, 0, prices, dp), f(index + 1, n, 1, prices, dp));
        }
        else
            profit = max(prices[index] + f(index + 1, n, 1, prices, dp), f(index + 1, n, 0, prices, dp));

        return dp[index][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {

        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, prices.size(), 1, prices, dp);
    }
};

// tabulation

int maxProfit(vector<int> &prices)
{

    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    for (int ind = prices.size() - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            }
            else
                profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);

            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// space optimized

int maxProfit(vector<int> &prices)
{
    vector<int> next(2, 0), curr(2, 0);
    for (int ind = prices.size() - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[ind] + next[0], next[1]);
            }
            else
                profit = max(prices[ind] + next[1], next[0]);

            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}