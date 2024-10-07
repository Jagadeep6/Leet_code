#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    stack<pair<int, int>> st;
    int m = matrix.size(), n = matrix.size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                st.push({i, j});
            }
        }
    }
    while (!st.empty())
    {
        int cur_r = st.top().first;
        int cur_c = st.top().second;
        st.pop();
        for (int i = 0; i < n; i++)
        {
            matrix[cur_r][i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            matrix[i][cur_c] = 0;
        }
    }
    return;
}