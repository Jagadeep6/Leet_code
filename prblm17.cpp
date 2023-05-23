#include <bits/stdc++.h>
using namespace std;

void solve(string digits, int i, string &cur, unordered_map<char, string>&m, vector<string> &res)
{
    if(i == digits.size())
    {
        res.push_back(cur);
        return;
    }
    string str = m[digits[i]];
    for(int j = 0; j < str.size(); j++)
    {
        cur.push_back(str[j]);
        solve(digits, i+1, cur, m, res);
        cur.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> res;
    if (digits.empty())
    {
        return res;
    }
    unordered_map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string cur = "";
    solve(digits, 0, cur, m, res);
    return res;
}

int main()
{
    vector<string> temp = letterCombinations("23");
    for(int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] <<' ';
    }
    cout <<endl;
    return 0;
}