#include <iostream>
#include <vector>
using namespace std;

// time complexity: O(log(n))
// space complexity: O(1)
// minimize the maximum amount
bool solution(int n, int m, long long int mid, vector<int> &time)
{
    long long int day = 1;
    long long int timeSum = 0;
    for (long long int i = 0; i < m; i++)
    {
        if (timeSum + time[i] <= mid)
        {
            timeSum += time[i];
        }
        else
        {
            day++;
            if (day > n || time[i] > mid)
            {
                return false;
            }
            timeSum = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long int s = 0;
    long long int e = 0;
    long long int ans = -1;
    for (long long int i = 0; i < m; i++)
    {
        e += time[i];
    }
    long long int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (solution(n, m, mid, time))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int n = 1;
    int m = 1;
    vector<int> time = {1};
    cout << ayushGivesNinjatest(n, m, time) << endl;
    return 0;
}