#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &nums)
{
    int target = accumulate(nums.begin(), nums.end(), 0);
    if(target%2 != 0)
    {
        return false;
    }
    target /= 2;
    cout << target << endl;
    unordered_set<int> dp;
    dp.insert(0);
    for(int i = 0; i < nums.size(); i++)
    {
        unordered_set<int> temp;
        for(auto it= dp.begin(); it != dp.end(); it++)
        {
            if(*it+nums[i] == target)
            {
                return true;
            }
            temp.insert(*it+nums[i]);
            temp.insert(*it);
        }
        dp = temp;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);
    return 0;
}