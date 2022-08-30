// same as 0 1 knapsack except that the supply of every item is infinite

#include <iostream>
#include <vector>
using namespace std;

// recursion with memoization
int f(int ind, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (W >= weight[ind])
            return (W / weight[ind]) * profit[ind];
        else
            return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notPick = f(ind - 1, W, profit, weight, dp);
    int pick = -1e9;
    if (W - weight[ind] >= 0)
        pick = profit[ind] + f(ind, W - weight[ind], profit, weight, dp);

    return dp[ind][W] = max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    int x = f(n - 1, w, profit, weight, dp);
    if (x <= -1e9)
        return 0;
    return x;
}

// tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int wt = 0; wt <= w; wt++)
    {
        if (wt >= weight[0])
            dp[0][wt] = (wt / weight[0]) * profit[0];
        else
            dp[0][wt] = 0;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {

            int notPick = dp[ind - 1][wt];
            int pick = -1e9;
            if (wt >= weight[ind])
                pick = profit[ind] + dp[ind][wt - weight[ind]];

            dp[ind][wt] = max(pick, notPick);
        }
    }
    if (dp[n - 1][w] <= -1e9)
        return 0;
    return dp[n - 1][w];
}

// space optimized tabulation

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);

    for (int wt = 0; wt <= w; wt++)
    {
        if (wt >= weight[0])
            prev[wt] = (wt / weight[0]) * profit[0];
        else
            prev[wt] = 0;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {

            int notPick = prev[wt];
            int pick = -1e9;
            if (wt >= weight[ind])
                pick = profit[ind] + curr[wt - weight[ind]];

            curr[wt] = max(pick, notPick);
        }
        prev = curr;
    }
    if (prev[w] <= -1e9)
        return 0;
    return prev[w];
}
