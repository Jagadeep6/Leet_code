#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &matrix, int i, vector<bool> &vis)
{
    vis[i] = true;
    for(int j = 0; j < matrix.size();j++)
    {
        if(!vis[j] and matrix[i][j] == 1)
        {
            solve(matrix, j, vis);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    vector<bool> vis(isConnected.size(), false);
    int res = 0;
    for(int i = 0; i < vis.size(); i++)
    {
        if(!vis[i])
        {
            solve(isConnected, i, vis);
            res++;
        }
    }
    return res;
}

int main()
{
}