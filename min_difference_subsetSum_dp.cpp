#include <iostream>
#include <vector>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    // preparing the dp array using subset sum method
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= totalSum)
        dp[0][arr[0]] = true;

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= totalSum; target++)
        {
            bool notPick = dp[index - 1][target];
            bool pick = false;
            if (arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];
            dp[index][target] = pick | notPick;
        }
    }
    int mini = 1e9;
    for (int s1 = 0; s1 <= totalSum / 2; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            int s2 = totalSum - s1;
            mini = min(mini, abs(s2 - s1));
        }
    }
    return mini;
}
