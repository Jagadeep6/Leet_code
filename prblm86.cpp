#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

ListNode *partition(ListNode *head, int x)
{
    ListNode* lessX = new ListNode();
    ListNode* greaterX = new ListNode();
    ListNode* temp = lessX;
    ListNode* temp_1 = greaterX;
    while(head!= NULL)
    {
        if(head -> val < x)
        {
            lessX->next = head;
            head = head ->next;
            lessX = lessX->next;
        }
        else
        {
            greaterX->next = head;
            head = head->next;
            greaterX = greaterX->next;
        }
    }
    lessX->next = temp_1->next;
    greaterX->next = NULL;
    return temp->next;
}