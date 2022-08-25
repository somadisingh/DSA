#include <iostream>
#include <vector>
using namespace std;

// solution using recursion and memoization
// time complexity: O(n)
// space complexity: O(n)
bool solve(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (n == 0)
        return (arr[0] == k);
    if (k < 0)
        return false;

    if (dp[n][k] != -1)
        return dp[n][k];

    bool notPick = solve(n - 1, k, arr, dp);
    bool pick = solve(n - 1, k - arr[n], arr, dp);

    return dp[n][k] = pick | notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

// solution using tabulation
// time complexity: O(target*k)
// space complexity: O(n*k)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = dp[index - 1][target];
            bool pick = false;
            if (arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];
            dp[index][target] = pick | notPick;
        }
    }
    return dp[n - 1][k];
}

// space optimized solution
// time complexity: O(n*k)
// space complexity: O(k*2)
bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = prev[target];
            bool pick = false;
            if (arr[index] <= target)
                pick = prev[target - arr[index]];
            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    return prev[k];
}