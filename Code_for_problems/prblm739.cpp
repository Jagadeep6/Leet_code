#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> & temperatures)
{
    cout << "bullshit";
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<pair<int, int>> st;
    st.push({temperatures[0], 0});
    for(int i = 1; i < n; i++)
    {
        cout << i << ':';
        if(temperatures[i] > st.top().first and !st.empty())
        {
            while(temperatures[i] > st.top().first and !st.empty())
            {
                int x = st.top().second;
                res[x] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        else
        {
            st.push({temperatures[i], i});
        }
    }
    return res;
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(temp);
    for(int i = 0; i < temp.size(); i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}