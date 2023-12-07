#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <algorithm>

using std::max;
using std::min;
using std::vector;
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
        {
            return 0;
        }

        int prev1 = 1;
        int prev2 = 1;

        for (int i = 1; i < s.length(); i++)
        {
            int current = 0;

            if (s[i] != '0')
            {
                current = prev1;
            }

            int value = stoi(s.substr(i - 1, 2));
            if (value >= 10 && value <= 26)
            {
                current += prev2;
            }

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};