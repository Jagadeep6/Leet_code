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


bool palindrome_list(ListNode* head)
{
   ListNode* slow = head;
   ListNode* fast = head;
   while(fast and fast->next)
   {
        slow = slow->next;
        fast = fast->next->next;
   }

   ListNode* prev = slow;
   slow = slow->next;
   prev->next = NULL;
    while(slow)
    {
        ListNode* temp = slow->next;
        slow ->next = prev;
        prev = slow;
        slow = temp;
    }
    slow = prev;
    fast = head;

    while(slow)
    {
        if(fast->val != slow->val)
        {
            return false;
        }
        else
        {
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    return true;

}

int main()
{
    int n;
    cin >> n;
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
    cout <<endl;
    cout << palindrome_list(head) << endl;

    return 0;
}