#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int solve(TreeNode* root, int &res)
{
    if(root == NULL)
    {
        return 0;
    }

    int l = solve(root->left, res);
    int r = solve(root->right, res);
    res = max(res, l+r+root->val);
    
    return root->val + max(l, r);
}

int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}