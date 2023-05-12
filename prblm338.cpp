#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> dp;
    for (int i = 0; i < n + 1; i++)
    {
        int sum = 0;
        int num = i;
        while (num != 0)
        {
            sum = sum + num % 2;
            num = num / 2;
        }
        dp.push_back(sum);
    }
    return dp;
}

int main()
{
    int n;
    cin >> n;
    vector <int> dp = countBits(n);
    for(int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << ' ';
    }
    return 0;
}