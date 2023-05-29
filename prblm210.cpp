#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int, vector<int>> &adj, unordered_set<int> &vis, unordered_set<int> &cycle, int course, vector<int> &res)
{
    if (cycle.find(course) != cycle.end())
    {
        return false;
    }
    if (vis.find(course) != vis.end())
    {
        return true;
    }

    cycle.insert(course);
    for (int i = 0; i < adj[course].size(); i++)
    {
        if (!dfs(adj, vis, cycle, adj[course][i], res))
        {
            return false;
        }
    }

    cycle.erase(course);
    vis.insert(course);
    res.push_back(course);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    unordered_set<int> vis;
    unordered_set<int> cycle;
    vector<int> res;

    for(int i = 0; i < numCourses; i++)
    {
        if(!dfs(adj,vis, cycle, i, res))
        {
            return {};
        }
    }

    return res;
}

int main()
{
}