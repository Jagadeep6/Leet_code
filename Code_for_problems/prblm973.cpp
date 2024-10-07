#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    unordered_map<int, vector<vector<int>>> mp;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < points.size(); i++)
    {
        int dis = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
        mp[dis].push_back({points[i][0], points[i][1]});
        heap.push(dis);
    }
    vector<vector<int>> res;
    for(int i = 0; i < k; i++)
    {
        int temp = heap.top();
        heap.pop();
        for(int i = 0; i < mp[temp].size(); i++)
        {
            res.push_back(mp[temp][i]);
        }
        mp[temp].clear();
    }

    return res;
}

int main()
{
    vector<vector<int>> points = {{1, 0}, {0, 1}};

}