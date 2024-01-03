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
    string minWindow(string s, string t)
    {
        if (t.empty())
        {
            return "";
        }

        unordered_map<char, int> countT, window;
        for (char c : t)
        {
            countT[c] = 1 + countT[c];
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.size(); ++r)
        {
            char c = s[r];
            window[c] = 1 + window[c];

            if (countT.find(c) != countT.end() && window[c] == countT[c])
            {
                have++;
            }

            while (have == need)
            {
                if (r - l + 1 < resLen)
                {
                    res = {l, r};
                    resLen = r - l + 1;
                }

                window[s[l]] -= 1;
                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]])
                {
                    have--;
                }

                l++;
            }
        }

        int start = res.first;
        int end = res.second;
        return resLen != INT_MAX ? s.substr(start, end - start + 1) : "";
    }
};