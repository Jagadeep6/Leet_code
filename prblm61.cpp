#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;



ListNode *rotateRight(ListNode *head, int k)
{
    if(head == NULL)
    {
        return head;
    }
    ListNode* temp = head;
    ListNode* end = head;
    while(end->next != NULL)
    {
        end = end->next;
    }
    cout << end->val;
    for(int i = 0; i < k; i++)
    {
        end->next = head;
        while(temp->next != end)
        {
            temp =temp->next;
        }
        temp->next = NULL;
        head = end;
        temp = head;
    }

    return temp;
}

int main()
{
}