#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<vector<int>> reverse_graph(graph.size());
    vector<int> indegree(graph.size(), 0);
    for(int i = 0; i < graph.size(); i++)
    {
        for(auto it : graph[i])
        {
            reverse_graph[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> res;
    for(int i = 0; i < graph.size(); i++)
    {
        if(indegree[i]== 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        res.push_back(temp);
        for(auto it: reverse_graph[temp])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    vector<int> res = eventualSafeNodes(graph);
    return 0;
}