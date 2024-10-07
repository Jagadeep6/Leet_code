#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

TreeNode* invert(TreeNode* root)
{
    if(root == nullptr)
    {
        return root;
    }
    invert(root->left);
    invert(root->right);
    TreeNode* temp = root->left;
    root -> left = root->right;
    root ->right = root->left;
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
}