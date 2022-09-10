#include <iostream>
#include <vector>

using namespace std;

#include <vector>
long f(long *values, int index, int n, bool buy, vector<vector<long>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    long profit = 0;

    if (buy)
    { // when (buy == true) either buy today or skip today and buy later
        profit = max(-values[index] + f(values, index + 1, n, 0, dp), f(values, index + 1, n, 1, dp));
    }
    else
    { // when (buy == false) either sell today or skip today and sell later
        profit = max(values[index] + f(values, index + 1, n, 1, dp), f(values, index + 1, n, 0, dp));
    }
    return dp[index][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return f(values, 0, n, 1, dp);
}