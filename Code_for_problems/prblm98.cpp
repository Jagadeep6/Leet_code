#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

class Solution
{
public:
    bool solve(TreeNode *root, long min_val, long max_val)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val >= max_val or root->val <= min_val)
        {
            return false;
        }
        return solve(root->left, min_val, root->val) and solve(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root)
    {
        return solve(root,LONG_MIN, LONG_MAX);    
    }
};