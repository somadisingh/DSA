/*
LEETCODE_NO = 494
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols
'+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and
concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

#include <iostream>
#include <vector>
using namespace std;

// recursion with memoization
// time complexity: O(index * target)
// space complexity: O(index * target) + ~O(index)
class Solution
{
public:
    int findWays(int ind, int tar, vector<int> &nums, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (tar == 0 && nums[0] == 0)
                return 2;
            if (tar == 0 || nums[ind] == tar)
                return 1;
            return 0;
        }

        if (dp[ind][tar] != -1)
            return dp[ind][tar];

        int notPick = findWays(ind - 1, tar, nums, dp);
        int pick = 0;
        if (tar >= nums[ind])
            pick = findWays(ind - 1, tar - nums[ind], nums, dp);

        return dp[ind][tar] = pick + notPick;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int totalSum = 0;
        for (auto &it : nums)
        {
            totalSum += it;
        }
        if (totalSum < target || (totalSum - target) % 2 != 0)
            return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(((totalSum - target) / 2) + 1, -1));
        return findWays(nums.size() - 1, (totalSum - target) / 2, nums, dp);
    }
};

// tabulation
int findTargetSumWays(vector<int> &nums, int target)
{

    int n = nums.size();
    int totalSum = 0;
    for (auto &it : nums)
    {
        totalSum += it;
    }
    if (totalSum < target || (totalSum - target) % 2 != 0)
        return 0;
    int tar = (totalSum - target) / 2;
    vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, 0));
    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (nums[0] != 0 && nums[0] <= tar)
        dp[0][nums[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= tar; t++)
        {

            int notPick = dp[ind - 1][t];
            int pick = 0;
            if (t - nums[ind] >= 0)
                pick = dp[ind - 1][t - nums[ind]];

            dp[ind][t] = pick + notPick;
        }
    }
    return dp[n - 1][tar];
}

// space optimized tabulation

int findTargetSumWays(vector<int> &nums, int target)
{

    int n = nums.size();
    int totalSum = 0;
    for (auto &it : nums)
    {
        totalSum += it;
    }
    if (totalSum < target || (totalSum - target) % 2 != 0)
        return 0;
    int tar = (totalSum - target) / 2;
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    if (nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (nums[0] != 0 && nums[0] <= tar)
        prev[nums[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= tar; t++)
        {

            int notPick = prev[t];
            int pick = 0;
            if (t - nums[ind] >= 0)
                pick = prev[t - nums[ind]];

            curr[t] = pick + notPick;
        }
        prev = curr;
    }
    return prev[tar];
}