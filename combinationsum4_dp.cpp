#include <bits/stdc++.h>
using namespace std;

//  solution using recursion and memoization
//  Time Complexity: O(N)
//  Space Complexity: O(N) + Space taken by recursion stack
int solve(vector<int> &num, int tar, vector<int> &dp)
{
    // base case
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;

    // memoization fetch
    if (dp[tar] != -1)
        return dp[tar];
    // recursive relation
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, -1);
    return solve(num, tar, dp);
}

// int main()
{
    int n, tar;
    cin >> n >> tar;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout << findWays(num, tar) << endl;
    return 0;
}

// solution using tabulation
// Time Complexity: O(N*tar)
// Space Complexity: O(tar)
int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1; // from base case
    // traverses from target 1 to tar
    for (int i = 1; i <= tar; i++)
    {
        // traverses num vector
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
            {
                dp[i] += dp[i - num[j]];
            }
        }
    }
    return dp[tar];
}