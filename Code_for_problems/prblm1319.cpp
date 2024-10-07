#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionRank(int u, int v)
    {
        int par_u = findParent(u);
        int par_v = findParent(v);

        if (par_u == par_v)
        {
            return;
        }

        if (rank[par_u] < rank[par_v])
        {
            parent[par_u] = par_v;
        }
        else if (rank[par_u] > rank[par_v])
        {
            parent[par_v] = par_u;
        }
        else
        {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }

    void unionSize(int u, int v)
    {
        int par_u = findParent(u);
        int par_v = findParent(v);

        if (par_u == par_v)
        {
            return;
        }
        if (size[par_u] < size[par_v])
        {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else
        {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};

int makeConnected(int n, vector<vector<int>> &connections)
{
    DisjointSet dU(n);
    int extraConnections = 0;
    for(auto i: connections)
    {
        int u = i[0];
        int v = i[1];
        if(dU.findParent(u) == dU.findParent(v))
        {
            extraConnections++;
        }
        else
        {
            dU.unionSize(u, v);
        }
    }
    int components = 0;
    for(int i = 0; i < n; i++)
    {
        if(dU.parent[i] == i)
        {
            components++;
        }
    }
    int ans = components -1;
    if(extraConnections >= ans)
    {
        return ans;
    }
    return  -1;
}

int main()
{
}