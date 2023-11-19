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
    int maxProduct(vector<int> &nums)
    {
        int minValue = nums[0];
        int maxValue = nums[0];
        int result = maxValue;

        for (int i = 1; i < nums.size(); i++)
        {
            int cur = nums[i];

            int temp = max(cur, max(cur * minValue, cur * maxValue));

            minValue = min(cur, min(cur * minValue, cur * maxValue));

            maxValue = temp;

            result = max(result, maxValue);
        }
        return result;
    }
};