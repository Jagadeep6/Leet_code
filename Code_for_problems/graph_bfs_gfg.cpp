#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adj[])
{
    vector<int> res;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            queue<int> q;
            vis[i] == true;
            q.push(i);
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                res.push_back(temp);
                vis[temp] = 1;
                for (auto i : adj[temp])
                {
                    if (vis[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
}