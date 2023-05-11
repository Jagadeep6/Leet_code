#include <bits/stdc++.h>
#include "tree.h"
using namespace std;
class Solution
{
public:
    void solve(TreeNode* root, int k , int &ans)
    {
        TreeNode* cur = root;
        int cnt = 0;
        while(cur != NULL)
        {
            if(cur->left == NULL)
            {
                cnt++;
                if(cnt == k)
                {
                    ans = cur ->val;
                }
                cur = cur->right;
            }
            else
            {
                TreeNode* prev = cur->left;
                while(prev->right!=NULL and prev->right != cur)
                {
                    prev = prev->right;
                }
                if(prev -> right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev ->right = NULL;
                    cnt++;
                    if(cnt == k)
                    {
                        ans = cur->val;
                    }
                    cur = cur->right;
                }
            }
        }
    }
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = 0;
        solve(root, k, ans);
        return ans;   
    }
};

int main()
{

}