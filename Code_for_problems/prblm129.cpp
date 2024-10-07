#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void dfs(TreeNode* curNode, string &temp, int &sum)
{
    if(curNode->left == NULL and curNode->right == NULL)
    {
        sum += stoi(temp);
        return;
    }
    if(curNode->left != NULL)
    {
        temp += to_string(curNode->left->val);
        dfs(curNode->left, temp, sum);
        temp.pop_back();
    }
    if(curNode->right != NULL)
    {
        temp += to_string(curNode->right->val);
        dfs(curNode->right, temp, sum);
        temp.pop_back();
    }
}

int sumNumbers(TreeNode* root)
{
    string temp = "";
    temp += to_string(root->val);
    //cout << temp;
    vector<string> res;
    int sum = 0;
    dfs(root, temp, sum);
    // for(auto it: res)
    // {
    //     sum += stoi(it);
    // }
    return sum;
}

int main()
{

}