#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int ans = -1, s = 0, e = nums.size() - 1, mid = s + (e - s) / 2, pivot;

        // handle corner case
        if (nums.size() == 1)
        {
            if (target == nums[0])
                return 0;
            else
                return ans;
        }

        if (nums.size() == 2)
        {
            if (target == nums[0])
                return 0;
            else if (target == nums[1])
                return 1;
            else
                return ans;
        }

        // step 1: find pivot element
        while (s <= e)
        {
            if (nums[mid - 1] > nums[mid])
            {
                pivot = mid;
                break;
            }
            if (nums[0] > nums[mid])
                e = mid;
            if (nums[0] < nums[mid])
                s = mid + 1;
            mid = s + (e - s) / 2;
        }

        // step 2: find the target
        if (pivot >= nums.size())
            pivot = 0;

        s = 0, e = nums.size() - 1;
        if (target <= nums[e])
        {
            s = pivot;
        }
        else
            e = pivot - 1;

        mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                break;
            }
            if (nums[mid] > target)
                e = mid - 1;
            if (nums[mid] < target)
                s = mid + 1;
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << s.search(nums, 5) << endl;
    return 0;
}
// time complexity: O(log(n))
// space complexity: O(1)