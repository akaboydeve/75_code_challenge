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
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b)
             { return a[0] < b[0]; });

        int res = 0;
        int prevEnd = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); ++i)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start >= prevEnd)
            {
                prevEnd = end;
            }
            else
            {
                res++;
                prevEnd = min(end, prevEnd);
            }
        }

        return res;
    }
};