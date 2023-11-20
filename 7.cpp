#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::max;
using std::min;
using std::vector;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums[0];

        if (nums.size() == 1)
        {
            return nums[0];
        }

        while (left <= right)
        {
            if (nums[left] < nums[right])
            {
                ans = min(ans, nums[left]);
            }
            int mid = (left + right) / 2;
            ans = min(ans, nums[mid]);
            if (nums[left] <= nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};