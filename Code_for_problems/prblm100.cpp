#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p== NULL and q == NULL)
        {
            return true;
        }
        if(p== NULL or q==NULL)
        {
            return false;
        }

        if(p->val == q->val)
        {
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        }

        return false;
    }
};