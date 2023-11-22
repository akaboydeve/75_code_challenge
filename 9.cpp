#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using std::max;
using std::min;
using std::vector;
using namespace std;

void sums(vector<int> &nums, int i, vector<vector<int>> &result)
{
    int left = i + 1;
    int right = nums.size() - 1;

    while (left < right)
    {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum < 0)
        {
            ++left;
        }
        else if (sum > 0)
        {
            --right;
        }
        else
        {
            result.push_back({nums[i], nums[left++], nums[right--]});
            while (left < right && nums[left] == nums[left - 1])
            {
                ++left;
            }
        }
    }
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                sums(nums, i, result);
            }
        }

        return result;
    }
};
