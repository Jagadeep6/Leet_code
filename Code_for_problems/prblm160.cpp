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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode* intersection = NULL;
    ListNode* temp = headA;
    
    while(temp != NULL)
    {
        ListNode* temp_b = headB;
        while(temp_b != NULL)
        {
            if(temp_b == temp)
            {
                return temp;
            }
            else
            {
                temp_b = temp_b -> next;
            }
        }
        temp = temp -> next;
    }

    return NULL;
}

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;
    for(int i = 1; i < n; i++)
    {
        cin >> x;
        temp -> next = new ListNode(x);
        temp = temp-> next;
    }
    temp = head;
    while (temp != NULL)
    {
        cout << temp -> val << "->";
        temp = temp -> next;
    }
    cout << endl;

    cin >> x;
    ListNode* head_b = new ListNode(x);
    temp = head_b;
    for(int i = 1; i < n; i++)
    {
        cin >> x;
        temp -> next = new ListNode(x);
        temp = temp-> next;
    }
    temp = head_b;
    while (temp != NULL)
    {
        cout << temp -> val << "->";
        temp = temp -> next;
    }
    cout << endl;

}