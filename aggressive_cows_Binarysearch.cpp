#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// maximize the minimum distance

bool solution(vector<int> &stalls, int k, int mid, int n)
{
    int cowCount = 1, position = stalls[0];
    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - position >= mid)
        {
            cowCount++;
            if (cowCount == k)
                return k;
            position = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int s = 0, n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int e = stalls[n - 1];
    int mid = s + (e - s) / 2;
    int ans;
    while (s <= e)
    {
        if (solution(stalls, k, mid, n))
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int n = 1;
    int m = 1;
    vector<int> time = {1};
    cout << aggressiveCows(time, m) << endl;
    return 0;
}