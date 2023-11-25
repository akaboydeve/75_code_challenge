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
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n != 0)
        {
            result = result + n % 2;
            n = n >> 1;
        }
        return result;
    }
};