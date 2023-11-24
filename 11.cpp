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
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int temp = (a & b) << 1;
            a = (a ^ b);
            b = temp;
        }
        return a;
    }
};