#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int start, vector<int> &cur, vector<vector<int>> &res)
{
    res.push_back(cur);
    for (int i = start; i < nums.size(); i++)
    {
        if (i > start and nums[i] == nums[i - 1])
        {
            continue;
        }
        cur.push_back(nums[i]);
        solve(nums, i + 1, cur, res);
        cur.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> cur;
    vector<vector<int>> res;
    int prev = INT_MIN;
    sort(nums.begin(), nums.end());
    solve(nums, 0, cur, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = subsetsWithDup(nums);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}