#include <bits/stdc++.h>
using namespace std;

int threeSumMulti(vector<int> &arr, int target)
{
    unordered_map<int, long> mp;
    for(auto it: arr)
    {
        mp[it]++;
    }
    long res = 0;
    int mod = 1e9+7;
    for(auto it: mp)
    {
        for(auto temp: mp)
        {
            int i = it.first, j = temp.first, k = target-i-j;
            if(mp.find(k)==mp.end())
            {
                continue;
            }
            if(i == j and j == k)
            {
                res += mp[i]*(mp[i]-1)*(mp[i]-2)/6;
            }
            else if(i == j and j != k)
            {
                res += mp[i]*(mp[i]-1)/2*mp[k];
            }
            else if(i < j and j < k)
            {
                res += mp[i]*mp[j]*mp[k];
            }
        }
    }

    return res%mod;
}