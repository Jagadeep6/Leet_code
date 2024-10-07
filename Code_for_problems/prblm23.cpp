#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class comp
{
    public:
    bool operator()(const ListNode* a, const ListNode* b)
    {
        return a->val > b->val;
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = new ListNode(0);
    ListNode* temp = head;
    priority_queue<ListNode*, vector<ListNode*>, comp> heap;
    for(int i = 0; i < lists.size(); i++)
    {
        if(lists[i] != NULL)
        {
            heap.push(lists[i]);
        }
    }

    while(!heap.empty())
    {
        ListNode* cur = heap.top();
        heap.pop();
        temp->next = cur;
        temp = temp->next;
        if(cur->next)
        {
            heap.push(cur->next);
        }
    }

    return head->next;
}
int main()
{
}