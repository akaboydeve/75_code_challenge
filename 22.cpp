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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int rob1 = 0, rob2 = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};