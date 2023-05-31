#include <bits/stdc++.h>
using namespace std;
//I mean this all right but slow as fuck
/*vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> st;
    for(int i = 0; i < nums.size(); i++)
    {
        set<int> mp;
        for(int j = i+1; j < nums.size(); j++)
        {
            int k = -(nums[i]+nums[j]);
            if(mp.find(k) != mp.end())
            {
                vector<int> temp = {k, nums[i], nums[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            mp.insert(nums[j]);
        }
    }
    vector<vector<int>>res(st.begin(), st.end());
    return res;
}*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i <nums.size(); i++)
    {
        if(i > 0 and nums[i]==nums[i-1])
        {
            continue;
        }
        int j = i+1;
        int k = nums.size() - 1;
        while( j < k)
        {
            int sum = nums[i]+nums[j]+nums[k];
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i],nums[j],nums[k]};
                res.push_back(temp);
                while(j < k and nums[j] == nums[j-1])
                {
                    j++;
                }
                while(j < k and nums[k] == nums[k+1])
                {
                    k--;
                }
            }
        }
    }
    return res;
}