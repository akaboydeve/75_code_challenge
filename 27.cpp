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

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;

    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> oldToNew;

    Node *cloneGraph(Node *node)
    {
        if (node)
        {
            return dfs(node);
        }
        else
        {
            return nullptr;
        }
    }

    Node *dfs(Node *node)
    {
        if (oldToNew.find(node) != oldToNew.end())
        {
            return oldToNew[node];
        }

        Node *copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node *nei : node->neighbors)
        {
            copy->neighbors.push_back(dfs(nei));
        }

        return copy;
    }
};