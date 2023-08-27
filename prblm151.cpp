#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string temp, res = "";
    int left = 0, right = s.size()-1;
    while(s[left] == ' ')
    {
        left ++;
    }
    while(s[right] == ' ')
    {
        right--;
    }

    while(left <= right)
    {
        if(s[left] != ' ')
        {
            temp += s[left];
        }
        else
        {
            if(s[left-1] == ' ')
            {
                left++;
                continue;
            }
            else
            {
                res = temp + " " + res;
                temp = "";
            }
        }
        left++;
    }
    res = temp + " " + res;
    res.erase(res.begin() + res.length()-1);
    return res;
}