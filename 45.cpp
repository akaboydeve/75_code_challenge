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
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> sub;
        int left = 0, right = 0, maxLength = 0;

        while (right < s.length())
        {
            if (sub.find(s[right]) == sub.end())
            {
                sub.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            }
            else
            {
                sub.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};