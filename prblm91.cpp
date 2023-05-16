#include <bits/stdc++.h>
using namespace std;
int convert(string s)
{
    if (s[0] == '0')
    {
        return -1;
    }
    return (int)(s[0] - 48) * 10 + (int)(s[1] - 48);
}

int numDecodings(string s)
{
    if(s[0]=='0')
    {
        return 0;
    }
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        int temp = stoi(s.substr(i-1,1));
        if(temp >= 1 and temp <= 9)
        {
            dp[i] += dp[i-1];
        }
        temp = stoi(s.substr(i-2, 2));
        if(temp >= 10 and temp <= 26)
        {
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}

int main()
{
    string s = "11106";
    cout << numDecodings(s) << endl;
    return 0;
}