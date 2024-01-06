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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<map<char, int>, vector<string>> mapS;

        for (const string &str : strs)
        {
            map<char, int> tempMap;

            for (char c : str)
            {
                tempMap[c]++;
            }

            mapS[tempMap].push_back(str);
        }

        vector<vector<string>> res;
        for (const auto &p : mapS)
        {
            res.push_back(p.second);
        }

        return res;
    }
};

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mapS;
        for (auto s : strs)
        {
            string word = s;
            sort(word.begin(), word.end());
            mapS[word].push_back(s);
        }
        vector<vector<string>> res;
        for (auto s : mapS)
        {
            res.push_back(s.second);
        }
        return res;
    }
};