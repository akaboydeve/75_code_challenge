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
    string longestPalindrome(string s)
    {
        string res = "";
        int resLen = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                if (r - l + 1 > resLen)
                {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                --l;
                ++r;
            }
        }

        for (int i = 0; i < s.length() - 1; ++i)
        {
            int l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                if (r - l + 1 > resLen)
                {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                --l;
                ++r;
            }
        }

        return res;
    }
};