#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_set>

using std::max;
using std::min;
using std::vector;
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int lcs = 0;

        unordered_set<int> numSet(nums.begin(), nums.end());

        for (auto num : nums)
        {
            int cs = 0, temp = num;
            if (numSet.find(temp + 1) != numSet.end())
                continue;
            while (numSet.find(temp) != numSet.end())
            {
                cs++;
                temp--;
            }
            lcs = max(lcs, cs);
        }

        return lcs;
    }
};