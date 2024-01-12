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
    int countSubstrings(string s)
    {
        int res = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }
        }

        return res;
    }
};