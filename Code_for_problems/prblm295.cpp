#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if(max_heap.empty())
        {
            max_heap.push(num);
            return;
        }

        if(max_heap.size() > min_heap.size())
        {
            if(max_heap.top() > num)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else
            {
                min_heap.push(num);
            }
        }
        else
        {
            if(min_heap.top() < num)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else
            {
                max_heap.push(num);
            }
        }
    }

    double findMedian()
    {
        double median = 0.0;
        if(max_heap.size()==min_heap.size())
        {
            median= (max_heap.top()+ min_heap.top())/2;
        }
        else
        {
            if(max_heap.size() > min_heap.size())
            {
                median = max_heap.top();
            }
            else
            {
                median = min_heap.top();
            }
        }
        return median;
    }
};
