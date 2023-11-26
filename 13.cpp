#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using std::max;
using std::min;
using std::vector;
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        ans[0] = 0;
        int offset = 1;
        for (int i = 1; i <= n; i++)
        {
            if (offset * 2 == i)
            {
                offset = i;
            }
            ans[i] = 1 + ans[i - offset];
        }
        return ans;
    }
};