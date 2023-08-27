#include <bits/stdc++.h>
using namespace std;

    class DisjointSet
    {
    public:
        vector<int> rank, size, parent;
        DisjointSet(int n)
        {
            rank.resize(n, 0);
            parent.resize(n);
            size.resize(n);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int node)
        {
            if (parent[node] == node)
            {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        int unionSize(int u, int v)
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
            else if (rank[par_v] < rank[par_u])
            {
                parent[par_v] = parent[par_u];
            }
            else
            {
                parent[par_v] = par_u;
                rank[par_u]++;
            }
        }
    };

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    DisjointSet dis(n);
    sort(accounts.begin(), accounts.end());
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < accounts[i].size(); j++)
        {
            string mailId = accounts[i][j];
            if(mp.find(mailId) == mp.end())
            {
                mp[mailId] = i;
            }
            else
            {
                dis.unionSize(i, mp[mailId]);
            }
        }
    }

    vector<string> mergedAccounts[n];
    for(auto it: mp)
    {
        string mail = it.first;
        int node = dis.findParent(it.second);
        mergedAccounts[node].push_back(mail);
    }

    vector<vector<string>> res;
    for(int i = 0; i < n; i++)
    {
        if(mergedAccounts[i].size() == 0)
        {
            continue;
        }
        sort(mergedAccounts[i].begin(), mergedAccounts[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it:mergedAccounts[i])
        {
            temp.push_back(it);
        }
        res.push_back(temp);
    }
    sort(res.begin(), res.end());
    return res;

}


int main()
{
}