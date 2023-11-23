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
    int maxArea(vector<int> &height)
    {
        int maxValue = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {

            int width = min(height[left], height[right]);
            int length = right - left;

            maxValue = max(maxValue, width * length);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxValue;
    }
};