#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int count = 0;
    for(int i = 0; i < strs[0].size(); i++)
    {
        for(int j = 0; j < strs.size(); i++)
        {
            if(i == strs[i].length() or strs[0][i] != strs[j][i])
            {
                goto line;
            }
        }
        count++;
    }
    line:
    return strs[0].substr(0, count);
}