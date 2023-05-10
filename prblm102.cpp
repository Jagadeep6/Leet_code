#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> level;
            for (int i = 0; i < s; i++)
            {
                TreeNode *cur = q.front();
                level.push_back(cur->val);
                q.pop();
                if (cur->left != NULL)
                {
                    q.push(cur->left);
                }
                if (cur->right != NULL)
                {
                    q.push(cur->right);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};