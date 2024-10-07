#include <bits/stdc++.h>
using namespace std;

int dofind(vector<int>&parent, int n)
{
    int p = parent[n];
    while(p!= parent[p])
    {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

bool Union(vector<int> &parent, vector<int> &rank, int m, int n)
{
    int m_par = dofind(parent, m);
    int n_par = dofind(parent, n);
    if(m_par == n_par)
    {
        return false;
    }
    if(rank[m_par] > rank[n_par])
    {
        rank[n_par] += rank[m_par];
        parent[n_par] = m_par;
    }
    else
    {
        rank[m_par] += rank[n_par];
        parent[m_par] = n_par;
    }
    return true;
}
vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> parents;
    vector<int> rank;
    for(int i = 0; i < n+1; i++)
    {
        parents.push_back(i);
        rank.push_back(1);
    }
    vector<int> res;
    for(int i = 0; i < n; i++)
    {
        int m = edges[i][0];
        int n = edges[i][1];
        if(!Union(parents, rank, m, n))
        {
            res = {m, n};
            break;
        }
    }

    return res;
}