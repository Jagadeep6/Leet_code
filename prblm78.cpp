#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int start, vector<int> &cur, vector<vector<int>> &res)
{
    res.push_back(cur);
    for(int i = start; i < nums.size(); i++)
    {
        cur.push_back(nums[i]);
        solve(nums, i+1, cur, res);
        
        cur.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> cur;
    vector<vector<int>> res;
    solve(nums, 0, cur, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 4, 5};
}