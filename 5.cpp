#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::max;
using std::vector;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curSum = 0;

        int maxSum = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            if (curSum < 0)
            {
                curSum = 0;
            }

            curSum = curSum + nums[i];

            maxSum = max(maxSum, curSum);
                }
        return maxSum;
    }
};