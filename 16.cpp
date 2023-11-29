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
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        int temp1 = 1, temp2 = 1;
        int result = 0;
        for (int i = 1; i < n; i++)
        {
            result = temp1 + temp2;
            temp2 = temp1;
            temp1 = result;
        }
        return result;
    }
};