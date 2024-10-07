#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
};

int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }
    int x = 1;
    int y = 2;
    for (int i = 0; i < n-2; i++)
    {
        int l = x+y;
        x = y;
        y = l;
    }
    return y;
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}