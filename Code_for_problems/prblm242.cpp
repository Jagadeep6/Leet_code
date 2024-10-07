#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> mp;
    if(s.length() != t.length())
    {
        return false;
    }
    for(int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        mp[t[i]]--;
    }
    for(char hm = 'a'; hm <= 'z'; hm++)
    {
        if(mp[hm])
        {
            return false;
        }
    }

    return true;
}

int main()
{
}