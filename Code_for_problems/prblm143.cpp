#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *cur = head;
    while (cur != NULL)
    {
        ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

ListNode *midoflist(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next and fast)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void reorderList(ListNode *head)
{
    ListNode *mid = midoflist(head);
    ListNode *new_list = reverseList(mid->next);
    mid  ->next = NULL;
    ListNode* begin = head;
    while(new_list)
    {
        ListNode* temp1 = begin ->next;
        ListNode* temp2 = new_list->next;
        begin ->next = new_list;
        new_list->next = temp1;
        begin = temp1;
        new_list = temp2;
    }
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    ListNode *head = new ListNode(x);
    ListNode *temp = head;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
    reorderList(head);
    temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    return 0;
}