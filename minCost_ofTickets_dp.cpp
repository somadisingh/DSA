#include <bits/stdc++.h>
using namespace std;

//  solution using recursion and memoization
//  Time Complexity: O(1)
//  Space Complexity: O(N) + Space taken by recursion stack
int solve(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    // base case
    if (index >= n)
        return 0;

    // memoization fetch
    if (dp[index] != -1)
        return dp[index];

    // option 1: 1 day pass
    int a = cost[0] + solve(n, days, cost, index + 1, dp);

    int i;
    // option 2: 7 day pass
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int b = cost[1] + solve(n, days, cost, i, dp);

    // option 3: 30 day pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int c = cost[2] + solve(n, days, cost, i, dp);

    dp[index] = min(a, min(b, c));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, -1);
    return solve(n, days, cost, 0, dp);
}

// int main()
{
    int n;
    cin >> n;
    vector<int> days(n);
    vector<int> cost(3);
    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> cost[i];
    }
    cout << minimumCoins(n, days, cost) << endl;
    return 0;
}

// solution using tabulation
// Time Complexity: O(N)
// Space Complexity: O(N)

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, INT_MAX); // because min needs to be calculated
    dp[n] = 0;

    for (int index = n - 1; index >= 0; index--)
    {

        // option 1: 1 day pass
        int a = cost[0] + dp[index + 1];

        int i;
        // option 2: 7 day pass
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;
        int b = cost[1] + dp[i];

        // option 3: 30 day pass
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;
        int c = cost[2] + dp[i];

        dp[index] = min(a, min(b, c));
    }
    return dp[0];
}
