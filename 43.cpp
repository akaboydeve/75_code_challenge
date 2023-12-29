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

#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int l = 0, r = matrix.size() - 1;

        while (l < r)
        {
            for (int i = 0; i < r - l; ++i)
            {
                int top = l;
                int bottom = r;

                int topLeft = matrix[top][l + i];
                matrix[top][l + i] = matrix[bottom - i][l];
                matrix[bottom - i][l] = matrix[bottom][r - i];
                matrix[bottom][r - i] = matrix[top + i][r];
                matrix[top + i][r] = topLeft;
            }

            ++l;
            --r;
        }
    }
};
