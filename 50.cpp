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
    bool isValid(string s)
    {
        stack<char> parenthesesStack;
        unordered_map<char, char> closeToOpen = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s)
        {
            if (closeToOpen.find(c) != closeToOpen.end())
            {
                if (!parenthesesStack.empty() && parenthesesStack.top() == closeToOpen[c])
                {
                    parenthesesStack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                parenthesesStack.push(c);
            }
        }

        return parenthesesStack.empty();
    }
};