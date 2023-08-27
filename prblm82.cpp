#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode* res = new ListNode(0, head);
    ListNode* cur = res;
    while(head != NULL)
    {
        if(head->next != NULL and head->val != head->next->val)
        {
            while(head->next != NULL and head->val != head->next->val)
            {
                head = head->next;
            }
            cur->next = head->next;
        }
        else
        {
            cur = cur->next;
        }
        head = head->next;
    }
    return res ->next;
}