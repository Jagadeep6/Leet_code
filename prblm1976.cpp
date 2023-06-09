#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<int>>graph(n, vector<int>(n, 0));
    for(auto it: roads)
    {
        graph[it[0]][it[1]] = it[2];
        graph[it[1]][it[0]] = it[2];
    }
    vector<int> dis(n, INT_MAX);
    vector<int> noOfWays(n, 0);
    
}



int main()
{
}