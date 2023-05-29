#include <bits/stdc++.h>
using namespace std;

/*bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
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
}*/

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<int> inDegree(numCourses);
    for(auto i : adj)
    {
        for(auto j : i.second)
        {
            inDegree[j]++;
        }
    }
    queue<int> q;
    for(int i =0; i < numCourses; i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto i :adj[temp])
        {
            inDegree[i]--;
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
    }

    if(ans.size() == numCourses)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    return 0;
}