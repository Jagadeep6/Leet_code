#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> arr)
{
    int n = arr.size();
    
    //vector<vector<int>>dp(n);
    int res = arr[0];
    bool ct = true;
    for(int i = 1; i < n; i++)
    {
        if(res + arr[i] > res)
        {
            ct = false;
            continue;
        }
        else if(res + arr[i] >= res and ct == true)
        {
            res = max(res, res+arr[i]);
        }
        else
        {
            res = max(res, arr[i]);
        }
    }

    return res;
}

int main()
{
    int n;
    vector<int> arr = {-2, -5, -1, -4, -3};
    int res = solve(arr);
    cout << res;
    return 0;
    
}
