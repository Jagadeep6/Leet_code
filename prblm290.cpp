#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string>mp;
    set<string> words_mapped;
    vector<string> words;
    stringstream ss(s);
    string word;
    while(getline(ss, word, ' '))
    {
        words.push_back(word);
    }

    if(words.size() != pattern.size())
    {
        return false;
    }
    
    for(int i = 0; i < pattern.size(); i++)
    {
        if(mp.find(pattern[i]) == mp.end())
        {
            if(words_mapped.find(words[i]) != words_mapped.end())
            {
                return false;
            }
            mp[pattern[i]] = words[i];
            words_mapped.insert(words[i]);
        }
        else
        {
            if(mp[pattern[i]] != words[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout << wordPattern("aaaa", "dog cat cat dog") << endl;
    return 0;
}