#include <bits/stdc++.h>
using namespace std;
vector<int> dir = {0, 1, 0, -1, 0};
int minimumEffortPath(vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair <int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
    pq.push({0 , {0, 0}});
    while(!pq.empty())
    {
        int dis = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if(r == m-1 and c == n-1)
        {
            return dis;
        }


        for(int i = 0; i < 4; i++)
        {
            int nr = r + dir[i];
            int nc = c + dir[i+1];

            if(nr < 0 or nr >= m or nc < 0 or nc >= n)
            {
                continue;
            }
            
            int cur = max(abs(heights[r][c] - heights[nr][nc]), dis);

            if(cur < efforts[nr][nc])
            {
                efforts[nr][nc] = cur;
                pq.push({cur, {nr, nc}});
            }

        }
        
    }

    return 0;
}

int main()
{
}