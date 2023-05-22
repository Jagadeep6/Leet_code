#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int target, int start, vector<vector<int>> &res, vector<int>&cur, int sum)
{
    if(sum > target)
    {
        return;
    }
    if(sum == target)
    {
        res.push_back(cur);
        return;
    }

    for(int i = start; i < candidates.size(); i++)
    {
        cur.push_back(candidates[i]);
        solve(candidates, target, i, res, cur, sum+candidates[i]);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>>res;
    vector<int> cur;
    solve(candidates, target, 0, res, cur, 0);
    return res;
}

int main()
{
}