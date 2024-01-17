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

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int res = root->val;

        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int
        {
            if (!node)
            {
                return 0;
            }

            int leftMax = max(dfs(node->left), 0);
            int rightMax = max(dfs(node->right), 0);

            res = max(res, node->val + leftMax + rightMax);

            return node->val + max(leftMax, rightMax);
        };

        dfs(root);

        return res;
    }
};