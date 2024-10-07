#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for(auto i:nums)
    {
        mp[i]++;
    }
    vector<int> v;
    for(auto i :mp)
    {
        v.push_back(i.first);
    }
    vector<int> dp(v.size()+1);
    sort(v.begin(), v.end());
    for(int i = v.size()-1; i>=0; i--)
    {
        int skip = 0+dp[i+1];
        int take = mp[v[i]]*v[i];
        if(v[i]+1==v[i+1] and i+1 < v.size())
        {
            take += dp[i+2];
        }
        else if(v[i]+1!=v[i+1] and i+1 < v.size())
        {
            take += dp[i+1];
        }
        dp[i] = max(skip, take);
    }
    return dp[0];
}

int main()
{
    vector<int> nums = {1};
    cout << deleteAndEarn(nums) << endl;
}