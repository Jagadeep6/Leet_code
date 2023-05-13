#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (coins.size() == 0 and amount > 0)
        {
            return -1;
        }
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (j >= coins[i - 1])
                {
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
                }
            }
        }

        if (dp[amount] == amount + 1)
        {
            return -1;
        }
        else
        {
            return dp[amount];
        }
    }
};

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }
    if (coins.size() == 0 and amount > 0)
    {
        return -1;
    }
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= coins.size(); i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j >= coins[i - 1])
            {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
    }

    if (dp[amount] == amount + 1)
    {
        return -1;
    }
    else
    {
        return dp[amount];
    }
}

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 11) << endl;
    return 0;
}