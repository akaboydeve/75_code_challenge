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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> preMap;
        for (const auto &pair : prerequisites)
        {
            preMap[pair[0]].push_back(pair[1]);
        }

        unordered_set<int> visitedSet;

        function<bool(int)> dfs = [&](int course) -> bool
        {
            if (visitedSet.count(course))
            {
                return false;
            }

            if (preMap[course].empty())
            {
                return true;
            }

            visitedSet.insert(course);
            for (int pre : preMap[course])
            {
                if (!dfs(pre))
                {
                    return false;
                }
            }
            visitedSet.erase(course);

            preMap[course].clear();
            return true;
        };

        for (int course = 0; course < numCourses; ++course)
        {
            if (!dfs(course))
            {
                return false;
            }
        }

        return true;
    }
};