#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void dfs(TreeNode* root, int &cur, int targetSum, bool &res)
{
    if(root == NULL)
    {
        return;
    }
    if(!root->left and !root->right)
    {
        cur+= root->val;
        if(cur == targetSum) res = true;
        cur -= root->val;
        return;
    }

    cur += root->val;
    dfs(root->left, cur, targetSum, res);
    dfs(root->right,cur, targetSum, res);
    cur -= root->val;   
    return;
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    if(root == NULL)
    {
        return false;
    }
    int cur = 0;
    bool res = false;
    dfs(root, cur, targetSum, res);
    return res;
}
int main()
{

}