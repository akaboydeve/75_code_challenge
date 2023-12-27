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
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> res;
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();

        while (left < right && top < bottom)
        {
            for (int i = left; i < right; ++i)
            {
                res.push_back(matrix[top][i]);
            }
            ++top;

            for (int i = top; i < bottom; ++i)
            {
                res.push_back(matrix[i][right - 1]);
            }
            --right;

            if (!(left < right && top < bottom))
            {
                break;
            }

            for (int i = right - 1; i >= left; --i)
            {
                res.push_back(matrix[bottom - 1][i]);
            }
            --bottom;

            if (!(left < right && top < bottom))
            {
                break;
            }

            for (int i = bottom - 1; i >= top; --i)
            {
                res.push_back(matrix[i][left]);
            }
            ++left;
        }

        return res;
    }
};