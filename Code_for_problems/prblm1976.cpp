#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<long long, long long>> adj[n];

        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        vector<long long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (1e9 + 7);
        pq.push({0, 0});
        while (!pq.empty())
        {
            long long d = pq.top().first;
            long long int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                long long adjnode = it.first;
                long long int edgwt = it.second;
                // this is the first time i have entered with short distance
                if ((d + edgwt) < dist[adjnode])
                {
                    dist[adjnode] = d + edgwt;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                }
                else if ((d + edgwt) == dist[adjnode])
                {
                    ways[adjnode] = ((ways[adjnode] % mod + ways[node]) % mod) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
//The below one is mine but failing some testcases might 6-7
/*
class Solution {
public:

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> graph(n);
    for(auto it: roads)
    {
        graph[it[0]].push_back({it[1], it[2]});
        graph[it[1]].push_back({it[0], it[2]});
    }
    vector<int> distanceFromSrc(n, INT_MAX);
    vector<int> noOfWays(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    distanceFromSrc[0] = 0;
    noOfWays[0] = 1;
    int mod = (int) (1e9+7);
    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: graph[node])
        {
            int adjNode = it.first;
            int weight = it.second;
            if(dis + weight < distanceFromSrc[adjNode])
            {
                distanceFromSrc[adjNode] = dis+weight;
                pq.push({dis + weight, adjNode});
                noOfWays[adjNode] = noOfWays[node];
                
            }
            else if(dis + weight == distanceFromSrc[adjNode])
            {
                noOfWays[adjNode] = (noOfWays[adjNode] + noOfWays[node])%(mod);
            }
        }
    }
    return noOfWays[n-1]%(mod);
}
};

*/
int main()
{
}