#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

ListNode *removeElements(ListNode *head, int val)
{
    while (head != NULL and head->val == val)
    {
        head = head->next;
    }
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->val == val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

int main()
{
}