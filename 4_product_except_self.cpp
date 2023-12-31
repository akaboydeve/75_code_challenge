#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::vector;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
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