#include <bits./stdc++.h>
#include "tree.h"
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if(root == NULL)
    {
        return res;
    }

    queue<TreeNode*> nodes;
    nodes.push(root);
    bool fromleft = true;
    while(!nodes.empty())
    {
        int size = nodes.size();
        vector<int> row(size);
        for(int i = 0; i < size; i++)
        {
            TreeNode* cur = nodes.front();
            nodes.pop();
            int index = (fromleft) ? i: size -i-1;
            row[index] = cur -> val;
            if(cur->left)
            {
                nodes.push(cur->left);
            }
            if(cur->right)
            {
                nodes.push(cur->right);
            }
        }
        fromleft != fromleft;
        res.push_back(row);
    }

    return res;
}