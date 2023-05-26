#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    int m = prerequisites.size();
    vector<vector<int>>adj_list(numCourses);
    for(int i = 0; i < m; i++)
    {
        adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    unordered_set<int>vis;
    for(int course = 0; course < numCourses; course ++)
    {
        if(!dfs(adj_list, vis, course))
        {
            return false;
        }
    }
    return true;

}

bool dfs(vector<vector<int>> &adj_list, unordered_set<int> &vis, int course)
{
    if(vis.find(course) != vis.end())
    {
        return false;
    }
    if(adj_list[course].empty())
    {
        return true;
    }
    vis.insert(course);
    for(int i = 0; i < adj_list[course].size(); i++)
    {
        int next = adj_list[course][i];
        if(!dfs(adj_list, vis, next))
        {
            return false;
        }
    }
    adj_list[course].clear();
    vis.erase(course);
    return true;
}