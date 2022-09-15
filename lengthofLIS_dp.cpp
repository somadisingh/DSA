#include <iostream>
#include <vector>

using namespace std;

// recursion with memoization
class Solution
{
public:
    int f(int ind, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        int notPick = 0 + f(ind + 1, prev, n, nums, dp);
        int pick = 0;
        if (prev == -1 || nums[ind] > nums[prev])
            pick = 1 + f(ind + 1, ind, n, nums, dp);

        return dp[ind][prev + 1] = max(pick, notPick);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, n, nums, dp);
    }
};

// tabulation

int lengthOfLIS(vector<int> &arr)
{

    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {

            int notPick = dp[ind + 1][prev + 1];
            int pick = 0;
            if (prev == -1 || arr[ind] > arr[prev])
            {
                pick = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev + 1] = max(pick, notPick);
        }
    }
    return dp[0][0];
}

int main()
{
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}