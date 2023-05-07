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

ListNode* reverse_list(ListNode* head)
{
    if(head ->next == NULL)
    {
        return head;
    }

    ListNode* rest = reverse_list(head-> next);
    head -> next -> next = head;
    head -> next = NULL;

    return rest;
}


ListNode* merged_sort(ListNode* a, ListNode* b)
{
    ListNode* final_res = NULL;
    if(a == NULL)
    {
        return b;
    }
    if(b == NULL)
    {
        return a;
    }

    if(a -> val > b -> val)
    {
       final_res = a;
       final_res -> next = merged_sort(a-> next, b); 
    }
    else
    {
        final_res = b;
        final_res -> next = merged_sort(a, b->next);
    }

    return final_res;
}


int main()
{
    ListNode* a
}