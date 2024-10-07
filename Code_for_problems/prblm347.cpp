#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> sol;
    for(int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    priority_queue<pair<int, int>> m;
    for(auto i : mp)
    {
        m.push(make_pair(i.second, i.first));
    }
    for(int i = 0; i < k; i++)
    {
        sol.push_back(m.top().second);
        m.pop();
    }
    return sol;
}

int main()
{
}