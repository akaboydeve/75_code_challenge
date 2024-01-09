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
    bool isPalindrome(std::string s)
    {
        int l = 0, r = s.length() - 1;
        while (l < r)
        {
            while (l < r && !isAlphaNum(s[l]))
            {
                l++;
            }
            while (r > l && !isAlphaNum(s[r]))
            {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

private:
    bool isAlphaNum(char c)
    {
        return (isalpha(c) || isdigit(c));
    }
};