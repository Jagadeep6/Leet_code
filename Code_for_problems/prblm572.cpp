#include <bits/stdc++.h>
#include "tree.h"

using namespace std;

vector<int> dfs(TreeNode *root)
{
    vector<int> df;
    if (root == nullptr)
    {
        return df;
    }

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *curr = s.top();
        s.pop();
        df.push_back(curr->val);
        if (curr->right != nullptr)
        {
            s.push(curr->right);
        }

        if (curr->left != nullptr)
        {
            s.push(curr->left);
        }
    }
    return df;
}

bool issame(TreeNode *root, TreeNode *subroot)
{
    if (!root and !subroot)
    {
        return true;
    }
    if (!root or !subroot)
    {
        return false;
    }

    if (root->val != subroot->val)
    {
        return false;
    }
    return issame(root->left, subroot->left) and issame(root->right, subroot->right);
}

bool subtree(TreeNode *root, TreeNode *subroot)
{
    if (!root or !subroot)
    {
        return false;
    }
    if (issame(root, subroot))
    {
        return true;
    }

    return subtree(root->left, subroot) or subtree(root->right, subroot);
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

    TreeNode *subroot = new TreeNode(2);
    subroot->left = new TreeNode(4);
    subroot->right = new TreeNode(6);
    // vector<int> df = dfs(root);
    // for (int i = 0; i < df.size(); i++)
    // {
    //     cout << df[i] << ' ';
    // }
    cout << subtree(root, subroot);
    cout << endl;
    return 0;
}