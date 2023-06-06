#include <bits/stdc++.h>
using namespace std;
class solution
{

public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < tasks.size(); i++)
        {
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto i : mp)
        {
            pq.push(i.second);
        }
        queue<pair<int, int>> q;
        int time = 0;

        while (!q.empty() or !pq.empty())
        {
            ++time;
            if (!pq.empty())
            {
                if (pq.top() - 1)
                {
                    q.push({pq.top() - 1, time + n});
                }
                pq.pop();
            }
            if (!q.empty() and q.front().second == time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    solution sol;
    cout << sol.leastInterval(tasks, 2);
    return 0;
}