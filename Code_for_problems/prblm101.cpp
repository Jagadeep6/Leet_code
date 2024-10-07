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

bool help(TreeNode* l, TreeNode* r)
{
    if(l == NULL and r == NULL)
    {
        return true;
    }
    else if(r == NULL || l == NULL)
    {
        return false;
    }
    if(r -> val == l -> val)
    {
        return help(l->left, r-> right) and help(l->right, r -> left);
    }
    return false;
}

int main()
{

}