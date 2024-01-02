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
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> count;
        int res = 0;
        int left = 0;
        int maxf = 0;

        for (int right = 0; right < s.length(); ++right)
        {
            count[s[right]] = 1 + count[s[right]];
            maxf = max(maxf, count[s[right]]);

            while ((right - left + 1) - maxf > k)
            {
                count[s[left]] -= 1;
                left += 1;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};