#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int left = 0, right = 0;
    unordered_map<char, int> mp;
    int res = 0;
    while(right < n)
    {
        if(mp.count(s[right]) != 0)
        {
            left = max(mp[s[right]]+1, left);
        }
        mp[s[right]] = right;
        res = max(res, right-left+1);
        right++;
    }

    return res;
}