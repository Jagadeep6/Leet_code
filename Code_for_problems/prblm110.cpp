#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int solve(TreeNode* root, bool &prev)
{
    if(!root and !prev)
    {
        return 0;
    }
    
    int l = solve(root->left, prev);
    int r = solve(root->right, prev);
    if(abs(l-r)>1)
    {
        prev = false;
    }
    return max(l,r)+1;

}
bool isBalanced(TreeNode *root)
{
    bool prev = true;
    solve(root, prev);
    return prev;
}