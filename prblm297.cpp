#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

string serialize(TreeNode *root)
{
    string data = "";
    queue<TreeNode*> q;
    if(root == NULL)
    {
        return data;
    }
    q.push(root);
    while(!q.empty())
    {   
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            data.append("#,");
        }
        else
        {
            data.append(to_string(temp->val)+',');
        }
        if(temp != NULL)
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return data;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if(data.size()==0)
    {
        return NULL;
    }
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        getline(s, str, ',');
        if(str=="#")
        {
            temp->left = NULL;
        }
        else
        {
            TreeNode* l = new TreeNode(stoi(str));
            q.push(l);
            temp ->left = l; 
        }
        getline(s, str, ',');
        if(str=="#")
        {
            temp->right = NULL;
        }
        else
        {
            TreeNode* r = new TreeNode(stoi(str));
            q.push(r);
            temp ->right = r; 
        }
    }
    return root;
}