#include <bits/stdc++.h>
using namespace std;

void dfs(map<string, vector<pair<string, double>>> &graph, double temp, double &ans, set<string> v, string src, string des)
{
    if(v.find(src) != v.end())
    {
        return;
    }
    else
    {
        v.insert(src);
        if(src == des)
        {
            ans = temp;
            return;
        }
        else
        {
            for(auto it:graph[src])
            {
                dfs(graph, temp*it.second, ans, v, it.first, des);
            }
        }
    }
}
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    map<string, vector<pair<string, double>>> graph;
    for(int i = 0; i < equations.size(); i++)
    {
        graph[equations[i][0]].push_back({equations[i][1], values[i]});
        graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
    }
    vector<double> res;
    for(int i = 0; i < queries.size(); i++)
    {
        string x = queries[i][0];
        string y = queries[i][1];
        set<string> vis;
        double ans = -1.0;
        if(graph.find(x) != graph.end())
        {
            dfs(graph, 1.0, ans, vis, x, y);
        }
        res.push_back(ans);
    }
    return res;
}



int main()
{
}