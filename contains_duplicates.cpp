#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::vector;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::map<int, int> countMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (countMap[nums[i]] == 1)
            {
                return true;
            }
            countMap[nums[i]]++;
        }
        return false;
    }
};