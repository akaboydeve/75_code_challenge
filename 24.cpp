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

        int one = 1;
        int two = 1;

        for (int i = 1; i < s.length(); i++)
        {
            int current = 0;

            if (s[i] != '0')
            {
                current = one;
            }

            int value = stoi(s.substr(i - 1, 2));
            if (value >= 10 && value <= 26)
            {
                current += two;
            }

            two = one;
            one = current;
        }

        return one;
    }
};