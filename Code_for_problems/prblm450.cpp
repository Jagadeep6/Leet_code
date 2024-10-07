#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

class Solution
{
public:
    TreeNode *findRight(TreeNode *root)
    {
        if (root->right == NULL)
        {
            return root;
        }
        return findRight(root->right);
    }
    TreeNode *solve(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        TreeNode *right_child = findRight(root->left);
        right_child->right = root->right;
        return root->left;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == key)
        {
            return solve(root);
        }
        TreeNode* temp = root;
        while(root != NULL)
        {
            if(root->val > key)
            {
                if(root->left != NULL and root->left->val == key)
                {
                    root->left = solve(root->left);
                    break;
                }
                else
                {
                    root = root ->left;
                }
            }
            else
            {
                if(root->right != NULL and root->right -> val == key)
                {
                    root -> right = solve(root ->right);
                    break;
                }
                else
                {
                    root = root -> right;
                }
            }
        }
    }
};