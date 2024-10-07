#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



vector<int> inorder_traversal(TreeNode* root)
{
    vector <int> res;
    stack<TreeNode*> st;
    while(true)
    {
        if(root != NULL)
        {
            st.push(root);
            root = root -> left;
        }
        else
        {
            if(st.empty())
            {
                break;
            }
            root = st.top();
            res.push_back(root-> val);
            st.pop();
            root = root -> right;
        }
    }
    return res;
}
