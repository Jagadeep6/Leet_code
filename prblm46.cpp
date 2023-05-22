#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<vector<int>> &res, int start)
{
    if (start == nums.size())
    {
        res.push_back(nums);
        for(int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = start; i < nums.size(); i++)
    {
        swap(nums[i], nums[start]);
        solve(nums, res, start+1);
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    solve(nums, res, 0);
    return res;
}

int main()
{
}