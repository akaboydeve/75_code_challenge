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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> output = {intervals[0]};

        for (const vector<int> &interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];

            int lastEnd = output.back()[1];

            if (start <= lastEnd)
            {
                output.back()[1] = max(lastEnd, end);
            }
            else
            {
                output.push_back({start, end});
            }
        }

        return output;
    }
};