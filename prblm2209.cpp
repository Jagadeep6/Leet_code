#include <bits/stdc++.h>
using namespace std;

// int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
// {
//     int n = floor.size();
//     vector<int> cnt(n, 0);
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (i == n - 1)
//         {
//             if (floor[i] == '0')
//                 cnt[i] = 0;
//             else
//                 cnt[i] = 1;
//         }
//         else
//         {
//             if (floor[i] == '0')
//                 cnt[i] = cnt[i + 1];
//             else
//                 cnt[i] = cnt[i + 1] + 1;
//         }
//     }
//     vector<vector<int>> dp(numCarpets + 1, vector<int>(n + 1, 0));
//     for (int i = n - 1; i >= 0; i--)
//     {
//         dp[0][i] = cnt[i];
//     }

//     for (int j = 1; j <= numCarpets; j++)
//     {
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (floor[i] == '1' && i + carpetLen < n)
//             {
//                 dp[j][i] = min(1 + dp[j][i + 1], dp[j - 1][i + carpetLen]);
//             }
//             else
//             {
//                 dp[j][i] = dp[j][i + 1];
//             }
//         }
//     }

//     for(int i = 0; i < numCarpets+1; i++)
//     {
//         for(int j = 0; j < n+1; j++)
//         {
//             cout << dp[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     cout << endl;
//     return dp[numCarpets][0];
// }

int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
{
    int n = floor.size();
    vector<vector<int>> dp(numCarpets+1, vector<int>(n+1, 0));
    
    for(int i = 0; i < numCarpets+1; i++)
    {
        for(int j = n-1; j >= 0; j--)
        {
            if(i == 0)
            {
                if(floor[j] == '0')
                {
                    dp[i][j] = dp[i][j+1];
                }
                else
                {
                    dp[i][j] = dp[i][j+1]+1;
                }
            }
            else
            {
                if(floor[j] == '1' and j+carpetLen < n)
                {
                    dp[i][j] = min(dp[i][j+1]+1, dp[i-1][j+carpetLen]);
                }
                else
                {
                    dp[i][j] = dp[i][j+1];
                }
            }    
        }
    }
    for(int i = 0; i < numCarpets+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return dp[numCarpets][0];
}

int main()
{
    cout << minimumWhiteTiles("10110101", 2, 2) << endl;
    return 0;
}