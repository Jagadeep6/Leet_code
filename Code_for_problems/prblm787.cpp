#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> cost(n, INT_MAX);
    cost[src] = 0;
    queue<pair<int, pair<int, int>>> q;
    vector<vector<pair<int, int>>> graph(n);
    //q for(k, {node, price});
    for(auto i: flights)
    {
        graph[i[0]].push_back({i[1], i[2]});
    }
    q.push({0, {src, 0}});

    while(!q.empty())
    {
        int cur = q.front().second.first;
        int stops = q.front().first;
        int price = q.front().second.second;
        q.pop();
        if(stops > k)
        {
            continue;
        }
        for(auto i: graph[cur])
        {
            if(price+i.second < cost[i.first] and stops <= k)
            {
                cost[i.first] = price+i.second;
                q.push({stops+1, {i.first, i.second+price}});
            }
        }
    }

    if(cost[dst] == INT_MAX)
    {
        return -1;
    }
    else
    {  
        return cost[dst];
    }
}

int main()
{
}