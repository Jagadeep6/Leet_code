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

ListNode* sort_list(ListNode* head)
{

}

ListNode* get_mid(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast -> next == NULL or fast != NULL)
    {
        fast = fast -> next-> next;
        slow = slow-> next;
    }
    return slow;
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
    cout << get_mid(head) -> val;
    cout << endl;
}