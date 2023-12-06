#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <algorithm>

using std::max;
using std::min;
using std::vector;
using namespace std;

class Solution
{
private:
    int rob1(vector<int> &nums, int start, int end)
    {
        int rob1 = 0, rob2 = 0;
        for (int i = start; i < end; ++i)
        {
            int newRob = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(rob1(nums, 1, n), rob1(nums, 0, n - 1));
    }
};