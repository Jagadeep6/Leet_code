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

ListNode *revers_list(ListNode *head)
{
    ListNode* cur = head;
    ListNode* prev = NULL;

    while(cur != NULL)
    {
        ListNode* upnext = cur->next;
        cur->next = prev;
        prev = cur;
        cur = upnext;
    }
    return prev;
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
}