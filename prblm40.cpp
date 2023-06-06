#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &candidates, int target, int sum, int start, vector<int> &cur, vector<vector<int>> &res)
{
    if (sum > target)
    {
        return;
    }
    if (sum == target)
    {
        res.push_back(cur);
        return;
    }

    for (int i = start; i < candidates.size(); i++)
    {
        if (i > start and candidates[i] == candidates[i - 1])
        {
            continue;
        }
        cur.push_back(candidates[i]);
        solve(candidates, target, sum + candidates[i], i + 1, cur, res);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>>res;
    vector<int> cur;
    solve(candidates, target, 0, 0, cur,res);
    return res;
}

int main()
{
}