#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    for(int i = 2; i < cost.size(); i++)
    {
        cost[i] += min(cost[i-1], cost[i-2]);
    }
    return min(cost[cost.size()-1], cost[cost.size()-2]);
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
}