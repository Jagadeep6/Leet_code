#include <bits/stdc++.h>
using namespace std;

void solve(int n, int close, int open, vector<string> &res, string temp)
{
    if (open == n and close == n)
    {
        res.push_back(temp);
    }

    if(open < n)
    {
        solve(n, close, open+1, res, temp+'(');
    }
    if(open > close)
    {
        solve(n, close+1, open, res, temp+')');
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string temp = "";
    solve(n, 0, 0, res, temp);
    return res;
}

int main()
{
    vector<string> res = generateParenthesis(3);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}