#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> mp, mp_2;
    for(int i = 0; i < s.size(); i++)
    {
        if(mp.find(s[i]) != mp.end() and mp[s[i]] != t[i]) return false;
        if(mp_2.find(t[i]) != mp_2.end() and mp_2[t[i]] != s[i]) return false;
        mp[s[i]] = t[i];
        mp_2[t[i]] = s[i];
    }
    return true;
}

int main()
{
    cout << isIsomorphic("egg", "add") << endl;
    cout << isIsomorphic("foo", "bar") << endl;
    cout << isIsomorphic("paper", "title") << endl;
    cout << isIsomorphic("badc", "baba") << endl;
    
    return 0;
}