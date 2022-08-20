#include <iostream>
#include <vector>
using namespace std;

// solution using recursion and memoization
int solve(int days, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (days == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != lastTask)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[days][lastTask] != -1)
        return dp[days][lastTask];

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != lastTask)
        {
            int point = points[days][i] + solve(days - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[days][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}

// solution using tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(point, dp[day][last]);
                }
            }
        }
    }
    return dp[n - 1][3];
}

// solution using space optimization
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, 0);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    temp[last] = max(points[day][task] + dp[task], temp[last]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}