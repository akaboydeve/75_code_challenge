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
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> mapS;
        for (char c : s)
        {
            mapS[c] = 1 + mapS[c];
        }

        for (char c : t)
        {
            if (mapS.find(c) == mapS.end() || mapS[c] == 0)
            {
                return false;
            }
            mapS[c] = mapS[c] - 1;
        }

        for (const auto &pair : mapS)
        {
            if (pair.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};