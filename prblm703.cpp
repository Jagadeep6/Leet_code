#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int> max_heap;
    int temp;
    KthLargest(int k, vector<int>& nums)
    {
        int temp = k;
        for(int i: nums)
        {
            max_heap.push(i);
        }
    }
    
    int add(int val)
    {
        max_heap.push(val);
        for(int i = 0; i < temp; i++)
        {
            max_heap.pop();
        }
        return max_heap.top();
    }

};