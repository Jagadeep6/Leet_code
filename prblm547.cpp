#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &isConnected, vector<bool> &vis, int start)
{
    vis[start] = true;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!vis[i] and isConnected[start][i] == 1)
        {
            solve(isConnected, vis, i);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    vector<bool> vis(isConnected.size(), false);
    int res = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if(!vis[i])
        {
            res++;
            solve(isConnected, vis, i);
        }
    }
    return res;
}

int main()
{
}