#include <iostream>
#include <vector>

using namespace std;

// approach 1: calculate prefix and suffix max. TC: O(n), SC: O(n)
class Solution
{
public:
    int trap(vector<int> &height)
    {

        int left = 0, right = 0, n = height.size();
        vector<int> leftMax(n), riteMax(n);

        for (int i = 0; i < n; i++)
        {
            left = max(left, height[i]);
            leftMax[i] = left;
            right = max(right, height[n - i - 1]);
            riteMax[n - i - 1] = right;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (min(leftMax[i], riteMax[i]) - height[i]);
        }
        return ans;
    }
};

// approach 2: two pointer approach. TC: O(n), SC: O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, leftmax = 0, rightmax = 0;
        int ans = 0;
        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] > leftmax)
                    leftmax = height[l];
                else
                    ans += (leftmax - height[l]);
                l++;
            }
            else
            {
                if (height[r] > rightmax)
                    rightmax = height[r];
                else
                    ans += (rightmax - height[r]);
                r--;
            }
        }
        return ans;
    }
};