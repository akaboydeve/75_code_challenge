#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using std::max;
using std::min;
using std::vector;
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sumN = (n * (n + 1) / 2);
        int sumArr = 0;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            sumArr = sumArr + nums[i];
        }
        result = sumN - sumArr;
        return result;
    }
};