#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums)
{
    unordered_set<int> mp(nums.begin(), nums.end());
    int res = 0;
    for(auto &i : mp)
    {
        int temp = 1;
        int cur = nums[i]+1;
        if(mp.find(nums[i]-1) == mp.end())
        {
            while(mp.find(cur) != mp.end())
            {
                temp++;
                cur++;
            }
            res = max(temp, res);
        }
    }
    return res;        
}

int main()
{
    vector<int> nums = {1, 2, 4, 5, 7, 3};
    cout << longestConsecutive(nums) << endl;

    return 0;
}