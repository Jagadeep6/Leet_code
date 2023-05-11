#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == NULL)
        {
            return NULL;
        }
        int cur = root -> val;
        if(cur < p->val and cur < q-> val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if(cur > p->val and cur > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return root;
        }
    }
};