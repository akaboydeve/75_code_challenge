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
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> amtDP(amount + 1, amount + 1);
        amtDP[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                if (i >= coins[j])
                {
                    amtDP[i] = min(amtDP[i], 1 + amtDP[i - coins[j]]);
                }
            }
        }

        if (amtDP[amount] < amount + 1)
        {
            return amtDP[amount];
        }
        return -1;
    }
};