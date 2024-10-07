#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

unordered_map<string, int> mp;

string solve(TreeNode *root, vector<TreeNode *> &res)
{
    if (!root)
    {
        return "#";
    }
    string s = solve(root->left, res) + ',' + solve(root->right, res) + ',' + to_string(root->val);
    mp[s]++;
    if (mp[s] == 2)
    {
        res.push_back(root);
    }
    return s;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    vector<TreeNode*> res;
    solve(root, res);
    return res;
}