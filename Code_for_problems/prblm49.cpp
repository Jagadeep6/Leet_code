#include <bits/stdc++.h>
using namespace std;

string get_map(string s)
{
    vector<int> cnt(26);
    for(int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'a']++;
    }
    string str = "";
    for(int i = 0; i < 26; i++)
    {
        str+=to_string(cnt[i]+'a');
    }
    return str;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for(int i = 0; i < strs.size(); i++)
    {
        string key = get_map(strs[i]);
        mp[key].push_back(strs[i]);
    }
    vector<vector<string>> res;
    for(auto it = mp.begin(); it!=mp.end(); it++)
    {
        res.push_back(it->second);
    }
    return res;
}

int main()
{
}