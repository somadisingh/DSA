#include <iostream>
#include <vector>
using namespace std;

bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (target < 0 || ind == 0)
        return false;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool pick = solve(ind - 1, target - arr[ind], arr, dp);
    bool notPick = solve(ind - 1, target, arr, dp);

    return dp[ind][target] = pick | notPick;
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
        return false;
    int target = sum / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve(n - 1, target, arr, dp);
}
