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
    void bfs(int srci, int srcj, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &a)
    {
        queue<int> qi, qj;
        vis[srci][srcj] = 1;
        qi.push(srci);
        qj.push(srcj);

        while (!qi.empty())
        {
            int i = qi.front();
            int j = qj.front();
            qi.pop();
            qj.pop();

            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (const auto &direction : directions)
            {
                int ni = i + direction[0];
                int nj = j + direction[1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] == 0 && a[ni][nj] == '1')
                {
                    vis[ni][nj] = 1;
                    qi.push(ni);
                    qj.push(nj);
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &a)
    {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] == '1' && vis[i][j] == 0)
                {
                    bfs(i, j, n, m, vis, a);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
