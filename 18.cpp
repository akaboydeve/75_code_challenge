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
    int lengthOfLIS(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        std::vector<int> LIS(n, 1);

        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] < nums[j])
                {
                    LIS[i] = std::max(LIS[i], 1 + LIS[j]);
                }
            }
        }

        return *std::max_element(LIS.begin(), LIS.end());
    }
};