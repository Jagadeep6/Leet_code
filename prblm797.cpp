#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<vector<int>>&res, vector<int> &path, int i)
{
    path.push_back(i);
    if(i == graph.size()-1)
    {
        res.push_back(path);
    }
    else
    {
        for(auto it: graph[i])
        {
            dfs(graph, res, path, it);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>>res;
    vector<int>path;
    dfs(graph, res, path, 0);
    return res;
}

int main()
{
}