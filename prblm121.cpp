#include <bits/stdc++.h>
using namespace std;
/*
int maxprofit(vector<int> prices)
{
    vector<int> dp = {-1};
    for(int i = 0; i < prices.size(); i++)
    {
        for(int j = i; j < prices.size(); j++)
        {
            if((prices[j] - prices[i]) > 0 and (prices[j] - prices[i]) > dp[dp.size() -1])
            {
                dp.push_back(prices[j] - prices[i]);
            }
        }
    }
    cout << endl;
    return dp[dp.size() - 1];
}
Higher time complexity
*/

int maxprofit(vector<int> prices)
{
    int m = prices[0];
    int profit = 0;
    for(int i = 0; i < prices.size(); i++)
    {
        int cost = prices[i] - m;
        profit = max(profit, cost);
        m = min(m, prices[i]);
    }
    return profit;
}


int main()
{
    int n;
    cin >> n;
    vector<int> prices(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxprofit(prices) << endl;

    return 0;
}  