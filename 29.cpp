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
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> ans;

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));

        for (int i = 0; i < m; ++i)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; ++j)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>> &h, vector<vector<bool>> &vis, int i, int j)
    {
        int m = h.size();
        int n = h[0].size();

        vis[i][j] = true;

        auto isValid = [&](int x, int y)
        {
            return x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && h[x][y] >= h[i][j];
        };

        if (isValid(i - 1, j))
            dfs(h, vis, i - 1, j);
        if (isValid(i + 1, j))
            dfs(h, vis, i + 1, j);
        if (isValid(i, j - 1))
            dfs(h, vis, i, j - 1);
        if (isValid(i, j + 1))
            dfs(h, vis, i, j + 1);
    }
};