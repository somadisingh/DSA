#include <iostream>
#include <vector>
using namespace std;

// recursion with memoization
int f(int index, vector<int> &num, int target, vector<vector<int>> &dp)
{

    if (index == 0)
    {
        if (target % num[index] == 0)
            return target / num[index];
        else
            return 1e9;
    }

    if (dp[index][target] != -1)
        return dp[index][target];

    int notPick = f(index - 1, num, target, dp);
    int pick = 1e9;
    if (target >= num[index])
        pick = 1 + f(index, num, target - num[index], dp);

    return dp[index][target] = min(pick, notPick);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int y = f(n - 1, num, x, dp);
    if (y == 1e9)
        return -1;
    return y;
}

// tabulation
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int t = 0; t <= x; t++)
    {
        if (t % num[0] == 0)
            dp[0][t] = t / num[0];
        else
            dp[0][t] = 1e9;
    }

    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= x; target++)
        {

            int notPick = dp[index - 1][target];
            int pick = 1e9;
            if (target >= num[index])
                pick = 1 + dp[index][target - num[index]];
            dp[index][target] = min(pick, notPick);
        }
    }
    if (dp[n - 1][x] >= 1e9)
        return -1;
    return dp[n - 1][x];
}

// space optimized

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x + 1, 0), curr(x + 1, 0);

    for (int t = 0; t <= x; t++)
    {
        if (t % num[0] == 0)
            prev[t] = t / num[0];
        else
            prev[t] = 1e9;
    }

    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= x; target++)
        {

            int notPick = prev[target];
            int pick = 1e9;
            if (target >= num[index])
                pick = 1 + curr[target - num[index]];
            curr[target] = min(pick, notPick);
        }
        prev = curr;
    }
    if (prev[x] >= 1e9)
        return -1;
    return prev[x];
}