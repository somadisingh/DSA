#include <iostream>
#include <vector>

using namespace std;

// recursion + memoization
class Solution
{
public:
    int f(int index, int n, bool buy, int transac, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        // base case: if last index crossed or transaction limit of 2 exhausted
        if (transac == 0 || index == n)
            return 0;
        if (dp[index][buy][transac] != -1)
            return dp[index][buy][transac];

        int profit = 0;

        if (buy)
        {
            profit = max(-prices[index] + f(index + 1, n, 0, transac, prices, dp), f(index + 1, n, 1, transac, prices, dp));
        } // if the stock is sold then the transaction has been completed hence transac-1
        else
            profit = max(prices[index] + f(index + 1, n, 1, transac - 1, prices, dp), f(index + 1, n, 0, transac, prices, dp));

        return dp[index][buy][transac] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        // 3 changing parameters: index, buy, transactionCount -> 3D DP
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))); // base case covered
        return f(0, n, 1, 2, prices, dp);
    }
};

// tabulation

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    // 3 changing parameters: index, buy, transactionCount -> 3D DP
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0))); // base case covered

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int tran = 1; tran <= 2; tran++)
            {
                int profit = 0;
                if (buy)
                {
                    dp[ind][buy][tran] = max(-prices[ind] + dp[ind + 1][0][tran], dp[ind + 1][1][tran]);
                }
                else
                    dp[ind][buy][tran] = max(prices[ind] + dp[ind + 1][1][tran - 1], dp[ind + 1][0][tran]);
            }
        }
    }
    return dp[0][1][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}

// constant space

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int tran = 1; tran <= 2; tran++)
            {
                if (buy)
                {
                    curr[buy][tran] = max(-prices[ind] + after[0][tran], after[1][tran]);
                }
                else
                    curr[buy][tran] = max(prices[ind] + after[1][tran - 1], after[0][tran]);
            }
        }
        after = curr;
    }
    return after[1][2];
}