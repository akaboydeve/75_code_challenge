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
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int total = 1; total <= target; ++total)
        {
            for (int num : nums)
            {
                if (total >= num)
                {
                    dp[total] += dp[total - num];
                }
            }
        }

        return dp[target];
    }
};