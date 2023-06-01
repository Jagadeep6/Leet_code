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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL or k == 1)
    {
        return head;
    }

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *cur = dummy, *next = dummy, *prev = dummy;
    int cnt = 0;
    while(cur ->next != NULL)
    {
        cur = cur -> next;
        cnt++;
    }
    while(cnt >= k)
    {
        cur = prev ->next;
        next = cur -> next;
        for(int i = 1; i < k; i++)
        {
            cur->next = next->next;
            next->next = prev->next;
            prev -> next = next;
            next = cur->next;
        }
        prev = cur;
        cnt -= k;
    }

    return dummy->next;
}   