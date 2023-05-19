#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void solve(TreeNode *root, int low, int high, int &ans)
{
    if(root == NULL)
    {
        return;
    }
    solve(root->left, low, high, ans);
    if(root->val >= low and root->val <= high)
    {
        ans += root->val;
    }
    solve(root->right, low, high, ans);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    solve(root, low, high, ans);
    return ans;
}