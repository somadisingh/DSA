#include <bits/stdc++.h>
using namespace std;

// USING RECURSION & MEMOISATION
// Time Complexity: O(N)
// Space Complexity: O(N)
int solve(vector<int> &nums, int i, vector<int> &dp)
{
    // base case
    if (i >= nums.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    // include
    int inc = solve(nums, i + 2, dp) + nums[i];
    // exclude
    int exc = solve(nums, i + 1, dp);

    dp[i] = max(inc, exc);
    return dp[i];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    if (nums.size() == 1)
        return nums[0];
    else
        return solve(nums, 0, dp);
}

// USING TABULATION
// SPACE COMPLEXITY: O(n)
// TIME COMPLEXITY: O(n)
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int inc = dp[i - 2] + nums[i];
        int exc = dp[i - 1];
        dp[i] = max(inc, exc);
    }
    return dp[n - 1];
}

// USING SPACE COMPLEXITY: O(1)
// TIME COMPLEXITY: O(n)
// suggested by github copilot
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int inc = nums[0];
    int exc = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = inc;
        inc = max(exc + nums[i], inc);
        exc = temp;
    }
    return max(inc, exc);
}

// my solution
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; i++)
    {
        int inc = prev2 + nums[i];
        int exc = prev1;
        int ans = max(inc, exc);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}