#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> heap;
    for(int i = 0; i < stones.size(); i++)
    {
        heap.push(stones[i]);
    }
    int x, y;
    while(heap.size() > 1)
    {
        x = heap.top();
        heap.pop();
        y = heap.top();
        heap.pop();
        if(y > x)
        {
            heap.push(y-x);
        }
    }
    if(heap.empty())
    {
        return 0;
    }
    return heap.top();
}


int main()
{
    vector<int> stones = {2, 7, 4, 8, 1, 1};
    cout << lastStoneWeight(stones) << endl;
    return 0;
}